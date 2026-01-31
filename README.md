# 42 Berlin - The Common Core

![42 Berlin](https://img.shields.io/badge/School-42_Berlin-black?style=for-the-badge&logo=42)
![Language](https://img.shields.io/badge/Language-C_%2F_C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B)
![Status](https://img.shields.io/badge/Status-Rank_4_(In_Progress)-success?style=for-the-badge)

## 👋 About
This repository documents my entire journey through the **Common Core** curriculum at **42 Berlin**. 

42 is a global coding school with no teachers, no classes, and a unique peer-to-peer learning model. The curriculum focuses on building deep computer science fundamentals from scratch—starting with recreating the C standard library and moving into advanced algorithms, graphics, system administration, and Object-Oriented Programming.

Currently, I am working on **Rank 4**, focusing on the transition from C to **C++**.

---

## 🗺️ Curriculum Progress

| Rank | Project | Description | Stack | Status |
|:---:|:---|:---|:---:|:---:|
| **0** | **[Libft](./libft)** | Your very first own C library. Re-coding standard C functions. | C, Makefile | ✅ |
| **1** | **[ft_printf](./ft_printf)** | Recreating the `printf` function. Focus on variadic arguments. | C | ✅ |
| **1** | **[get_next_line](./get_next_line)** | Reading a line from a file descriptor. Focus on static variables. | C | ✅ |
| **1** | **Born2beroot** | System Administration. Setting up a secure Debian server (LVM, SSH, UFW). | Bash, VM | ✅ |
| **2** | **[push_swap](./push_swap)** | Sorting data on a stack with a limited set of instructions using the lowest possible number of moves. | C, Algos | ✅ |
| **2** | **[so_long](./so_long)** | A small 2D game. Textures, sprites, and event handling. | C, MiniLibX | ✅ |
| **2** | **[pipex](./pipex)** | Simulating the Unix pipe mechanism `\|`. File descriptors and redirection. | C, Unix | ✅ |
| **3** | **[minishell](./minishell)** | A functional shell. Parsing, executors, built-ins, and signal handling. | C, Bash | ✅ |
| **3** | **[philosophers](./philosophers)** | The Dining Philosophers problem. Threads, mutexes, and concurrency. | C, Threads | ✅ |
| **4** | **[CPP Modules 00-04](./cpp)** | Introduction to OOP: Classes, polymorphism, inheritance, and templates. | C++ | 🚧 |
| **4** | **[NetPractice](./netpractice)** | Networking exercises (Subnets, TCP/IP, Routing). | Network | ⏳ |
| **5** | **CPP Modules 05-09** | Advanced C++: Exceptions, casting, templates, and containers (STL). | C++ | ⏳ |
| **5** | **Inception** | System Administration using Docker. Setting up a LEMP stack. | Docker | ⏳ |
| **5** | **webserv** | Writing an HTTP server from scratch. (Or ft_irc). | C++ | ⏳ |
| **6** | **ft_transcendence** | The final project. A full-stack SPA Pong game with chat and multiplayer. | TS, NestJS | ⏳ |

---

## 🏆 Project Highlights

### 🐚 Minishell
*Rank 3 | Group Project*
**"As beautiful as a shell."**
A surprisingly complex project requiring us to recreate a functional Unix shell (like bash).
* **Key Challenges:** Writing a custom lexer/parser, managing abstract syntax trees (AST), handling environment variables, implementing pipes/redirections, and managing signals (`Ctrl-C`, `Ctrl-D`, `Ctrl-\`).
* **Skills:** Process creation (`fork`, `execve`), file descriptor manipulation, defensive programming.

### 🍝 Philosophers
*Rank 3 | Concurrency*
**"I eat, therefore I am."**
A solution to the classic Dining Philosophers problem. The goal is to prevent philosophers from dying of starvation while managing shared resources (forks) without getting into data races or deadlocks.
* **Key Challenges:** Synchronization, avoiding race conditions, optimizing CPU usage.
* **Skills:** Threads (`pthread`), Mutexes, Semaphores, Time management.

### 🎨 So_long
*Rank 2 | Graphics*
A small 2D game where a character collects items and escapes a map.
* **Key Challenges:** Handling window management, rendering textures (X11/Cocoa), and key-hook events.
* **Skills:** MiniLibX (42's graphics library), game loops, map parsing.

### 📊 Push_swap
*Rank 2 | Algorithms*
An algorithmic challenge to sort a stack of numbers using two stacks and a specific set of operations, aiming for the lowest complexity.
* **Algorithm Used:** [e.g., Radix Sort / Turk Algorithm / Quick Sort].
* **Skills:** Complexity analysis (Big O), stack manipulation, bitwise operations.

### 🧪 Pipex
*Rank 2 | Unix Mechanism*
Recreating the behavior of the shell command: `< infile cmd1 | cmd2 > outfile`.
* **Skills:** Deep understanding of `pipe()`, `dup2()`, and `fork()`.

---

## 🛠️ Skills & Technologies

* **Languages:** C (Expert), C++ (Intermediate), Shell Scripting.
* **Tools:** Git, Vim, Valgrind, GDB, Makefiles, Docker (upcoming).
* **Systems:** Unix/Linux architecture, File Descriptors, Memory Management (malloc/free), Concurrency (Threads/Processes).
* **Soft Skills:** Peer-to-peer code reviews, teamwork (Minishell), self-learning.

---

## 📬 Contact

* [Webseite](https://www.sgavrilov.de)
* [LinkedIn](https://www.linkedin.com/in/sergej-gavrilov)

---
*Created by [Your Name]. All projects are compliant with the 42 Norminette.*
