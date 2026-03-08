#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

void    timer_handler(int signum)
{
    (void)signum;
}

int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
    pid_t           pid;
    int             status;
    struct sigaction sa;
    // 1. Setup the signal handler for the timeout
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = timer_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL);
    // 2. Fork the process
    pid = fork();
    if (pid == -1)
        return (-1);
    // 3. Child Process: Run the function
    if (pid == 0)
    {
        f();
        exit(0); // If f() returns, exit successfully
    }
    // 4. Parent Process: Set the timer
    alarm(timeout);
    // 5. Wait for the child
    if (waitpid(pid, &status, 0) == -1)
    {
        // If waitpid failed because of a signal (EINTR), it was our timeout
        if (errno == EINTR)
        {
            kill(pid, SIGKILL);       // Kill the stuck child
            waitpid(pid, NULL, 0);    // Cleanup the zombie
            if (verbose)
                printf("Bad function: timed out after %u seconds\n", timeout);
            return (0);
        }
        return (-1); // Some other error occurred
    }
    // 6. Disable the alarm immediately if the child finished early!
    alarm(0);
    // 7. Check Exit Status
    if (WIFEXITED(status))
    {
        int exit_code = WEXITSTATUS(status);
        if (exit_code == 0)
        {
            if (verbose)
                printf("Nice function!\n");
            return (1);
        }
        else
        {
            if (verbose)
                printf("Bad function: exited with code %d\n", exit_code);
            return (0);
        }
    }
    // 8. Check Signal Termination (Segfaults, Aborts, etc.)
    if (WIFSIGNALED(status))
    {
        if (verbose)
            printf("Bad function: %s\n", strsignal(WTERMSIG(status)));
        return (0);
    }
    return (-1);
}
