*This project has been created as part of the 42 curriculum by alehamad.*

# get_next_line

A function that reads a file descriptor one line at a time, written from scratch in C with `read` and a static buffer.

![language](https://img.shields.io/badge/language-C-000000?style=flat-square)
![school](https://img.shields.io/badge/school-42-000000?style=flat-square)

## Overview

**get_next_line** returns the next line of a file descriptor each time it is called, until the end of the file. It works on regular files, standard input, pipes or sockets, whatever the size of the lines.

The goal of the project is to understand:

- how `read` works, and why it can return less than a full line or more than one line
- how a **static variable** keeps data between two calls of the same function
- how to manage **dynamic memory** carefully when a buffer grows over several reads
- how the size of the read buffer (`BUFFER_SIZE`) changes the number of system calls

The same code is also part of my [libft](https://github.com/Skulay/libft), in `src/print/`.

## Features

| Feature | Details |
|---|---|
| Return value | The line read, **including** its `\n`, in a newly allocated string. The last line has no `\n` if the file does not end with one |
| End of file | Returns `NULL` once everything has been read, and frees what it kept |
| Errors | Returns `NULL` on a negative fd, a `read` error, a failed allocation or `BUFFER_SIZE <= 0` |
| Any buffer size | Works with `BUFFER_SIZE=1` as well as `BUFFER_SIZE=10000000` |
| Several fds *(bonus)* | The bonus version keeps one buffer per fd, so several files can be read in turn without mixing their lines |

## Build

### Requirements

- `cc` / `gcc` / `clang`

### Compile

There is no `Makefile`: the files are meant to be compiled with your own program. `BUFFER_SIZE` defaults to `42` and can be set at compile time.

```bash
git clone <repository-url> get_next_line
cd get_next_line

# mandatory version
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c

# bonus version (several fds)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c
```

### Options

| Macro | Default | Effect |
|---|---|---|
| `BUFFER_SIZE` | `42` | Number of bytes read by each call to `read` |
| `MAX_FD` | `1024` | Highest fd the bonus version can handle (size of the buffer array) |

## Usage

```c
#include "get_next_line.h"

char *get_next_line(int fd);
```

The caller must `free` every line it gets back.

## How it works

```
 get_next_line(fd)
        │
        ▼
 read_file ──► read BUFFER_SIZE bytes ──► append to stash ──► '\n' in stash?
        │                 ▲                                         │
        │                 └──────────────── no ─────────────────────┤
        │                                                           yes / EOF
        ▼                                                           │
 extract_line ◄─────────────────────────────────────────────────────┘
   copy stash up to and including '\n' ──► returned line
        │
        ▼
 extract_rest
   keep what comes after '\n' in stash for the next call
```

### 1. The stash — `get_next_line.c`

A `static char *stash` keeps the bytes that were read but not returned yet. In the bonus version it becomes `static char *stash[MAX_FD]`, one per fd: that is the only difference between the two versions.

### 2. Reading — `read_file`

Reads `BUFFER_SIZE` bytes at a time and appends them to the stash with `gnl_strjoin_free`, until the stash contains a `\n` or `read` returns `0`. It stops as soon as a full line is available, so it never reads more than needed.

### 3. Extracting — `extract_line`, `extract_rest`

`extract_line` copies the stash up to and including the first `\n`. `extract_rest` replaces the stash with what follows, or frees it and sets it to `NULL` when nothing is left.

### 4. Helpers — `get_next_line_utils.c`

| Function | Role |
|---|---|
| `gnl_strlen` | Length, `0` for `NULL` |
| `gnl_strchr` | Looks for the `\n` in the stash |
| `gnl_strdup` | First copy into an empty stash |
| `gnl_strjoin_free` | Joins stash and buffer, then frees the old stash |

## Project structure

```
.
├── get_next_line.h                # prototypes, default BUFFER_SIZE
├── get_next_line.c                # one static stash
├── get_next_line_utils.c          # string helpers
├── get_next_line_bonus.h          # same, plus MAX_FD
├── get_next_line_bonus.c          # one stash per file descriptor
└── get_next_line_utils_bonus.c
```

## Examples

```c
#include "get_next_line.h"
#include <stdio.h>

int main(int ac, char **av)
{
    int     fd;
    char    *line;

    (void)ac;
    fd = open(av[1], O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("[%s]", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

```console
$ printf 'first line\nsecond line\nlast line without newline' > a.txt
$ cc -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c && ./a.out a.txt
[first line
][second line
][last line without newline]
```

## Testing

- `BUFFER_SIZE` of `1`, `42`, `10000000`
- empty file, file without a final `\n`, file with only `\n`, very long lines
- reading from standard input (`fd = 0`) and from an invalid fd
- several files read in turn with the bonus version
- `valgrind` for leaks, including when the reading stops before the end of the file

## Resources

- `man 2 read`, `man 2 open`
- [Static local variables in C](https://en.cppreference.com/w/c/language/storage_duration)

## Author

| Login | Work |
|---|---|
| **alehamad** | Everything |
