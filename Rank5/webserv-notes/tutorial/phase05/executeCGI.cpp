#include "defines.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <sys/wait.h>

std::string executeCGI(const std::string &script_path, const HttpRequest &req,
                       const std::string &body) {
  int pipe_in[2];  // Server -> Script (stdin)
  int pipe_out[2]; // Script -> Server (stdout)

  if (pipe(pipe_in) < 0 || pipe(pipe_out) < 0) {
    return "HTTP/1.1 500 Internal Server Error\r\n\r\nPipe failed";
  }

  pid_t pid = fork();
  if (pid < 0) {
    return "HTTP/1.1 500 Internal Server Error\r\n\r\nFork failed";
  }

  if (pid == 0) {
    // CHILD Process (becomes the Python Script)
    close(pipe_in[1]);  // Child doesn't write to input pipe
    close(pipe_out[0]); // Child doesn't read from output pipe

    // Map the pipes to standard input (0) and standard output (1)
    dup2(pipe_in[0], STDIN_FILENO);
    dup2(pipe_out[1], STDOUT_FILENO);

    close(pipe_in[0]);
    close(pipe_out[1]);

    // Setup the environment variables (CGI standard)
    // Note: C++98 requires strict char* arrays for execve
    std::string env_method = "REQUEST_METHOD=" + req.method;

    std::ostringstream cl_stream;
    cl_stream << "CONTENT_LENGTH=" << body.length();
    std::string env_length = cl_stream.str();

    char *envp[] = {const_cast<char *>(env_method.c_str()),
                    const_cast<char *>(env_length.c_str()), NULL};

    // Setup the arguments to run Python
    char *args[] = {const_cast<char *>("/usr/bin/python3"),
                    const_cast<char *>(script_path.c_str()), NULL};

    // Execute the external program
    execve(args[0], args, envp);

    // If execve fails, the child must die immediately to avoid zombie processes
    std::cerr << "Execve failed!" << std::endl;
    exit(1);
  } else {
    // PARENT Process (The Web Server)
    close(pipe_in[0]);  // Server doesn't read from input pipe
    close(pipe_out[1]); // Server doesn't write to output pipe

    // 1. Send the chunked HTTP body to the script's stdin
    write(pipe_in[1], body.c_str(), body.length());
    close(pipe_in[1]); // Close it so the script knows we are done sending data

    // 2. Wait for the script to finish processing
    int status;
    waitpid(pid, &status, 0);

    // 3. Read the script's output
    char read_buffer[4096] = {0};
    std::string cgi_output;
    int bytes_read;

    while ((bytes_read = read(pipe_out[0], read_buffer, sizeof(read_buffer))) >
           0) {
      cgi_output.append(read_buffer, bytes_read);
    }
    close(pipe_out[0]);

    // Combine the CGI output with a successful HTTP response line
    return "HTTP/1.1 200 OK\r\n" + cgi_output;
  }
}
