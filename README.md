# Simple Shell Project

## Description
A simple UNIX command line interpreter implemented in C that replicates basic shell functionality.

This project is part of the Holberton School curriculum and demonstrates understanding of:
- Process creation and management
- System calls (fork, execve, wait)
- PATH environment variable handling
- Command parsing and execution
- Memory management

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

### Interactive Mode
```bash
$ ./hsh
($) ls
AUTHORS README.md main.c
($) /bin/pwd
/home/user/simple_shell
($) exit
```

### Non-Interactive Mode
```bash
$ echo "ls" | ./hsh
AUTHORS README.md main.c
$ echo "pwd" | ./hsh
/home/user/simple_shell
```

## Built-in Commands

| Command | Description |
|---------|-------------|
| `exit [status]` | Exit the shell with optional status code |
| `env` | Display all environment variables |

## Features
- Execute commands using absolute paths
- Execute commands using PATH resolution
- Handle command-line arguments
- Implement built-in commands
- Proper error handling and reporting
- Memory leak prevention

## Project Structure

| File | Description |
|------|-------------|
| `main.c` | Program entry point |
| `loop.c` | Main shell loop |
| `execute.c` | Command execution |
| `parser.c` | Command parsing and tokenization |
| `path_utils.c` | PATH resolution utilities |
| `builtins.c` | Built-in command implementations |
| `shell.h` | Header file with function prototypes |
| `man_1_simple_shell` | Manual page |

## Authors
- Shaden Khaled
- Own Algarni

## License
This project is part of the Holberton School curriculum.
