# 🐚 Minishell 1 — Unix Command Interpreter in C

[![Language: C](https://img.shields.io/badge/Language-C-00599C.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Build: Make](https://img.shields.io/badge/Build-Makefile-orange.svg)](Makefile)
[![Module: B-PSU-200](https://img.shields.io/badge/Epitech-B--PSU--200-blue.svg)](https://www.epitech.eu/)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Academic Year: 2024-2025](https://img.shields.io/badge/Academic%20Year-2024--2025%20(Tek1)-blueviolet.svg)](#)

> **Minishell 1 is the foundational Unix shell implementation**, exploring process control, system calls, and environment management.

---

## ⚙️ Features

- **Command Line Parsing:** Tokenizes commands and arguments, stripping leading/trailing whitespace.
- **PATH Lookup:** Scans the `PATH` environment variable to locate binary executables.
- **Process Spawning:** Implements `fork()` and `execve()`, catching execution errors and reporting exit codes.
- **Built-in Commands:**
  - `cd [path]`: Directory navigation with `~` and `-` support.
  - `setenv [VAR [VAL]]`: In-memory environment variable creation/update.
  - `unsetenv VAR`: Environment variable removal.
  - `env`: Displays the current environment.
  - `exit [code]`: Exits the shell session.

---

## 🛠️ Build & Usage

```bash
make
./mysh
```

---

## 📜 License

Licensed under the **MIT License with attribution** to Lucas Lhomme (Crabe).
