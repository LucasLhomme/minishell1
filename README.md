# Minishell 1

> **Interactive Unix shell in C.**

## Overview
Command-line interpreter built around process management and system calls:
- Interactive prompt with line edition
- Binary lookup through the `PATH` environment variable
- Process execution using `fork`, `execve`, and `waitpid`
- Shell built-in commands: `cd`, `env`, `setenv`, `unsetenv`, `exit`

## Build & Usage
```bash
make
./mysh
```

## License
Open-source under MIT License.
