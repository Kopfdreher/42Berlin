# Pipex
Replicating the Pipe "|" in command line.

## Launch
It launches like "./pipex infile cmd1 cmd2 > outfile"

In Shell it behaves like "< infile cmd1 | cmd2 > outfile"

## Roadmap

### Phase 1: Research & "Toy" Code (1-2 Days)
**Goal:** Understand the system calls individually before combining them.
**Method:** Create a folder called `tests/` and write tiny, throwaway `main.c` files.

**Step 1.1: Master `fork()`**
* **Read:** `man fork` (focus on the return value).
* **Task:** Write a program that forks.
    * If `pid == 0`, print "I am the child".
    * If `pid > 0`, print "I am the parent".
* **Check:** Run it. Do both lines appear?

**Step 1.2: Master `execve()`**
* **Read:** `man execve`.
* **Task:** Write a program that executes `ls -l`.
    * **Note:** You need to pass the full path `/bin/ls` manually for now.
    * **Note:** The arguments array must end with `NULL`.
* **Key Insight:** Notice that any code *after* `execve` never runs (unless `execve` fails).

**Step 1.3: Master `pipe()` & `dup2()`**
* **Read:** `man pipe`, `man dup2`.
* **Task:**
    1.  Create a pipe.
    2.  Fork.
    3.  **Child:** Redirect stdout to the pipe write-end (`dup2`). Run `ls`.
    4.  **Parent:** Read from the pipe read-end. Print what you read to the terminal.

---

### Phase 2: The Logic "Skeleton" (1 Day)
**Goal:** Build the structure without the complex parsing.
**Method:** Hardcode values to get the logic flowing.

**Step 2.1: Hardcoded Pipex**
Write a program that **only** does exactly this: `< infile /bin/ls | /bin/wc > outfile`.
* Don't parse `envp`.
* Don't parse arguments.
* Manually type `/bin/ls` and `/bin/wc` into your `execve` calls.
* **Why?** This isolates the hardest logical bug (process synchronization) from the hardest algorithmic task (string parsing).

**Step 2.2: The "Hanging" Check**
* Run your hardcoded program. Does it finish?
* **Common Bug:** If the cursor blinks forever, you didn't close a file descriptor.
* **Rule:** The parent must close the pipe ends *after* forking but *before* waiting.

---

### Phase 3: The Environment Parser (1-2 Days)
**Goal:** Make it dynamic. Turn `ls` into `/bin/ls`.
**Method:** String manipulation (Libft style).

**Step 3.1: Find PATH**
* Create `char *find_path(char *cmd, char **envp)`.
* Loop through `envp` looking for "PATH=".

**Step 3.2: Split and Join**
* Use `ft_split` on the PATH line (delimiter via `:`).
* Loop through the resulting paths:
    1.  Join the path with a `/`.
    2.  Join that with your command (e.g., `ls`).
    3.  Use `access(full_path, F_OK | X_OK)` to see if it exists.
    4.  If yes, return it. If no, free and check the next one.

---

### Phase 4: Assembly & Error Handling (1 Day)
**Goal:** Bring it all together and make it bulletproof.

**Step 4.1: Integration**
* Replace your hardcoded `/bin/ls` from Phase 2 with your `find_path` function from Phase 3.
* Parse `argv` to get the filenames and commands.

**Step 4.2: Leaks and Errors**
* **Valgrind:** Run `valgrind --leak-check=full --trace-children=yes ./pipex ...`
    * *Note:* `--trace-children=yes` is vital because `fork` creates new processes valgrind needs to watch.
* **File Descriptors:** Use `valgrind --track-fds=yes`. Ensure all FDs are closed at the end.
* **Perror:** If `open` fails (e.g., infile doesn't exist), use `perror("Error")` to print the exact system error message.

---

### Summary Checklist

1.  [ ] **Research:** Read man pages for `pipe`, `fork`, `dup2`, `execve`, `access`.
2.  [ ] **Drill:** Write a standalone script that just opens a file and prints it.
3.  [ ] **Drill:** Write a standalone script that executes `/bin/ls`.
4.  [ ] **Code:** Implement the `find_path` parsing logic.
5.  [ ] **Code:** Implement the `parent` and `child` logic with hardcoded paths.
6.  [ ] **Integration:** Connect parsing to execution.
7.  [ ] **Feedback:** Test with invalid files, permission errors, and invalid commands.

**Next Step:**
I recommend starting with **Phase 1, Step 1.2 (`execve`)**. This is often the most confusing function because it replaces the process memory.

Would you like me to write a small "Toy Code" example for `execve` so you can analyze it?
