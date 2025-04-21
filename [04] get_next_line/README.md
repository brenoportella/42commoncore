# get_next_line - 42 Project

`get_next_line` is a 42 project that challenges students to implement a function that reads a line from a file descriptor. It aims to develop skills in file I/O, buffer handling, memory management, and static variables in C.

## Objective

Implement the function `get_next_line` that returns a line from a file descriptor, reading efficiently and handling buffers correctly. The function must work for any file and support multiple file descriptors simultaneously.

---

## Compilation

To compile the library, simply run:

```bash
make
```

This will generate an archive named `get_next_line` containing the compiled object files.

### Available Makefile Commands

| Command       | Description                                 |
|---------------|---------------------------------------------|
| `make`        | Compiles the source files and creates archive |
| `make clean`  | Removes object files                        |
| `make fclean` | Removes object files and archive            |
| `make re`     | Cleans and rebuilds the project             |

---

## Structure

- **SRCS**: Source files `get_next_line.c` and `get_next_line_utils.c`.
- **OBJS**: Compiled object files.
- **Makefile**: Automates the build process.

---

## Features

- Efficiently reads from a file descriptor until a newline (`\n`) or end-of-file (EOF) is reached.
- Handles reading from multiple file descriptors simultaneously.
- Works with any file or input stream (stdin, files, etc.).
- Ensures proper memory handling and no leaks.

---

## Technical Notes

The Makefile line:
```make
ar rcs $(NAME) $(OBJS)
```
uses the `ar` utility to create a static archive:
- `r`: insert object files
- `c`: create the archive
- `s`: write an index

This wraps all `.o` files into a single archive named `get_next_line`.

> Note: Although this project outputs an archive, it's typically used by including the `.c` files directly in your build in later 42 projects.

---

## Status

Fully implemented and working correctly
Handles all standard edge cases and supports multiple FDs.
