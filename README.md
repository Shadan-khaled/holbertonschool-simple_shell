# Simple Shell

## Description
A simple UNIX command interpreter written in C that replicates basic shell functionality.

Part of Holberton School curriculum.

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

### Interactive Mode
```bash
$ ./hsh
($) ls
AUTHORS README.md
($) exit
```

### Non-Interactive Mode
```bash
$ echo "ls" | ./hsh
AUTHORS README.md
```

## Built-in Commands
- `exit [status]` - Exit shell
- `env` - Print environment variables

## Features
- Execute commands with absolute/relative paths
- PATH resolution
- Command arguments support
- Built-in commands
- Error handling
- Memory management

## Files
- `main.c` - Entry point
- `loop.c` - Main shell loop
- `execute.c` - Command execution
- `parser.c` - Command parsing
- `path_utils.c` - PATH resolution
- `builtins.c` - Built-in commands
- `shell.h` - Header file

## Authors
- Shaden Khaled
- Owen Algarni
