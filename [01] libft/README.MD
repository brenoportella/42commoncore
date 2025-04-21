# Libft - 42 Project

This project is part of the 42 school curriculum. The goal is to create a static C library — `libft` — which includes a collection of functions that replicate standard C library functions, as well as some additional utilities.

## Objective

Reimplement common functions from the C standard library (libc) and provide other useful functions that will assist in future projects at 42.

---

## Compilation

To compile the library, simply run:

```bash
make
```

This will generate the `libft.a` static library containing all implemented functions.

### Available Makefile Commands

| Command       | Description                                  |
|---------------|----------------------------------------------|
| `make`        | Compiles the source files and creates `libft.a` |
| `make clean`  | Removes object files                         |
| `make fclean` | Removes object files and `libft.a`           |
| `make re`     | Cleans and rebuilds the project              |

---

## Structure

- **SRCS**: List of `.c` source files that make up the library.
- **OBJDIR**: Directory where compiled object `.o` files are stored.
- **libft.a**: The compiled static library.
- **Makefile**: Automates the build process.

---

## Functions Implemented

### Standard libc functions:
- `ft_atoi`
- `ft_bzero`
- `ft_calloc`
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- `ft_memchr`, `ft_memcmp`, `ft_memcpy`, `ft_memmove`, `ft_memset`
- `ft_strchr`, `ft_strlcat`, `ft_strlcpy`, `ft_strlen`, `ft_strncmp`, `ft_strnstr`, `ft_strrchr`
- `ft_tolower`, `ft_toupper`

### Additional functions:
- `ft_strdup`
- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_itoa`
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- `ft_strmapi`
- `ft_striteri`

---

## Technical Notes

The following Makefile line:
```make
ar rcs $(NAME) $(OBJS)
```
uses `ar` to create a static library:
- `r`: insert files into the archive.
- `c`: create the archive if it does not exist.
- `s`: write an index to the archive.

This command packages all `.o` files into the `libft.a` file.

---

## Status

Project complete and ready for reuse 
This library will serve as a foundation for many upcoming 42 projects.
