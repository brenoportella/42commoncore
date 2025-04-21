# ft_printf - 42 Project

`ft_printf` is a custom implementation of the standard `printf` function in C. This project is part of the 42 school's curriculum and aims to deepen the understanding of variadic functions, parsing, and formatted output handling.

## Objective

Recreate the functionality of `printf`, handling various format specifiers and producing formatted output to the standard output (stdout). The function should mimic the behavior of the original `printf` as closely as possible.

---

## Compilation

To compile the library, run:

```bash
make
```

This will create the `libftprintf.a` static library containing the `ft_printf` implementation and its helper functions.

### Available Makefile Commands

| Command       | Description                                  |
|---------------|----------------------------------------------|
| `make`        | Compiles the source files and creates `libftprintf.a` |
| `make clean`  | Removes object files                         |
| `make fclean` | Removes object files and `libftprintf.a`     |
| `make re`     | Cleans and rebuilds the project              |

---

## Structure

- **SRCS**: List of `.c` source files (`ft_printf.c`, `ft_aux.c`) that make up the project.
- **libftprintf.a**: The compiled static library.
- **Makefile**: Handles the build process.

---

## Features

Supported format specifiers include:
- `%c` – Character
- `%s` – String
- `%p` – Pointer
- `%d` / `%i` – Signed decimal integer
- `%u` – Unsigned decimal integer
- `%x` / `%X` – Unsigned hexadecimal (lowercase / uppercase)
- `%%` – Literal percent sign

The implementation ensures correct handling of:
- Flags and field widths
- Memory management
- Edge cases and undefined behaviors

---

## Technical Notes

This line in the Makefile:
```make
ar rcs $(NAME) $(OBJS)
```
uses `ar` to create a static archive:
- `r`: insert object files into the archive
- `c`: create the archive if it doesn't exist
- `s`: write an index to the archive

This combines all `.o` files into `libftprintf.a`.

---

## Status

Project successfully implemented and tested
Ready to be used in other projects that require formatted output.
