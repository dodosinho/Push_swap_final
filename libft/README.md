*This project has been created as part of the 42 curriculum by mohfall.*

# Libft - Your Very First Own Library

## Description

**Libft** is the first project in the 42 curriculum. The goal of this project is to recreate essential functions from the standard C library (`libc`), alongside additional utility functions for memory management, string manipulation, file descriptor output, and linked list handling.

In C programming, building a library from scratch develops an in-depth understanding of memory layout, pointers, dynamic memory allocation (`malloc`, `free`), and algorithmic efficiency. The resulting static library (`libft.a`) serves as a foundational toolset that can be reused across subsequent 42 projects.

---

## Technical Specifications

- **Program Name:** `libft.a`
- **Compiler Flags:** `-Wall -Wextra -Werror` (forbidden to compile with `-std=c99` or use the `restrict` keyword)
- **Library Tool:** Built using `ar rcs` (`libtool` is strictly forbidden)
- **Global Variables:** Strictly forbidden
- **Helper Functions:** Defined as `static` to restrict scope to the appropriate file
- **Structure:** All `.c`, `Makefile`, and `libft.h` files must reside at the root of the repository

---

## Library Contents & Features

The library is organized into three distinct parts:

### Part 1 - Libc Reimplementations

These functions replicate standard C library functions with identical behavior and prototypes (prefixed with `ft_`). Character check functions return `1` for true and `0` for false.

| Function | Description | Prototype |
| :--- | :--- | :--- |
| `ft_isalpha` | Tests for an alphabetic character | `int ft_isalpha(int c);` |
| `ft_isdigit` | Tests for a digit (`0` through `9`) | `int ft_isdigit(int c);` |
| `ft_isalnum` | Tests for any alphanumeric character | `int ft_isalnum(int c);` |
| `ft_isascii` | Tests whether `c` is a 7-bit US-ASCII character | `int ft_isascii(int c);` |
| `ft_isprint` | Tests for any printable character including space | `int ft_isprint(int c);` |
| `ft_strlen` | Computes the length of a string | `size_t ft_strlen(const char *s);` |
| `ft_memset` | Fills memory with a constant byte | `void *ft_memset(void *s, int c, size_t n);` |
| `ft_bzero` | Erases the data in the `n` bytes of memory by writing zeros | `void ft_bzero(void *s, size_t n);` |
| `ft_memcpy` | Copies memory area (non-overlapping) | `void *ft_memcpy(void *dest, const void *src, size_t n);` |
| `ft_memmove` | Copies memory area handling overlap safely | `void *ft_memmove(void *dest, const void *src, size_t n);` |
| `ft_strlcpy` | Size-bounded string copy | `size_t ft_strlcpy(char *dst, const char *src, size_t size);` |
| `ft_strlcat` | Size-bounded string concatenation | `size_t ft_strlcat(char *dst, const char *src, size_t size);` |
| `ft_toupper` | Converts character to uppercase | `int ft_toupper(int c);` |
| `ft_tolower` | Converts character to lowercase | `int ft_tolower(int c);` |
| `ft_strchr` | Locates first occurrence of character in string | `char *ft_strchr(const char *s, int c);` |
| `ft_strrchr` | Locates last occurrence of character in string | `char *ft_strrchr(const char *s, int c);` |
| `ft_strncmp` | Compares two strings up to `n` bytes | `int ft_strncmp(const char *s1, const char *s2, size_t n);` |
| `ft_memchr` | Scans memory for a character | `void *ft_memchr(const void *s, int c, size_t n);` |
| `ft_memcmp` | Compares memory areas | `int ft_memcmp(const void *s1, const void *s2, size_t n);` |
| `ft_strnstr` | Locates a substring in a string with bounded search length | `char *ft_strnstr(const char *big, const char *little, size_t len);` |
| `ft_atoi` | Converts an initial portion of a string to an integer | `int ft_atoi(const char *nptr);` |
| `ft_calloc` | Allocates memory for an array and zeroes it (returns unique pointer if `nmemb` or `size` is `0`) | `void *ft_calloc(size_t nmemb, size_t size);` |
| `ft_strdup` | Duplicates a string using dynamic memory allocation | `char *ft_strdup(const char *s);` |

---

### Part 2 - Additional Functions

These utility functions either do not exist in the standard C library or exist in different forms, aiding string manipulation and file descriptor I/O.

| Function | Prototype | Description |
| :--- | :--- | :--- |
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len);` | Allocates and returns a substring from string `s` starting at index `start` with max length `len`. |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2);` | Allocates and returns a new string, concatenating `s1` and `s2`. |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set);` | Allocates and returns a copy of `s1` with characters specified in `set` trimmed from start and end. |
| `ft_split` | `char **ft_split(char const *s, char c);` | Splits `s` into an array of strings delimited by character `c`. Array is NULL-terminated. |
| `ft_itoa` | `char *ft_itoa(int n);` | Allocates and returns a string representing integer `n` (handles negative numbers). |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Applies function `f` to each character of string `s` by index, returning a newly allocated result string. |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char*));` | Applies function `f` to each character of `s` by address, allowing in-place modification. |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd);` | Outputs character `c` to the specified file descriptor `fd`. |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd);` | Outputs string `s` to the specified file descriptor `fd`. |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd);` | Outputs string `s` followed by a newline to the specified file descriptor `fd`. |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd);` | Outputs integer `n` to the specified file descriptor `fd`. |

---

### Part 3 - Linked List Functions

The linked list part relies on the `t_list` structure defined in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Prototype | Description |
| :--- | :--- | :--- |
| `ft_lstnew` | `t_list *ft_lstnew(void *content);` | Allocates and initializes a new node with given `content` and `next = NULL`. |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new);` | Adds node `new` at the beginning of the list `lst`. |
| `ft_lstsize` | `unsigned int ft_lstsize(t_list *lst);` | Counts and returns the number of nodes in the list. |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst);` | Returns the pointer to the last node of the list. |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new);` | Adds node `new` at the end of the list `lst`. |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Frees node content using function `del`, then frees the node itself. |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *));` | Deletes and frees given node and all successors with `del`, setting pointer to `NULL`. |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *));` | Iterates over the list, applying `f` to the content of each node. |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` | Iterates and creates a new list from successive applications of `f`. Cleans up on failure. |

---

## Instructions

### Compilation Rules

The project must include a `Makefile` that compiles all `.c` files into object `.o` files and packages them into `libft.a` using `ar rcs`.

The Makefile implements the following mandatory targets:
- `make` or `make all`: Compiles the library and creates `libft.a`.
- `make clean`: Removes generated object files (`*.o`).
- `make fclean`: Removes object files and `libft.a`.
- `make re`: Cleans and recompiles everything from scratch.

```bash
# Clone the repository
git clone <repository_url> libft
cd libft

# Compile the library
make

# Clean object files
make clean

# Full rebuild
make re
```

### Linking with an External Project

To use `libft.a` in another C project:

1. Include the header file in your C source code:
   ```c
   #include "libft.h"
   ```

2. Compile your application linking against `libft.a`:
   ```bash
   cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
   ```

---

## Resources

### References & Documentation
- **Linux Programmer's Manual (man pages):** `man 3 strlen`, `man 3 memcpy`, `man 3 memmove`, `man 3 malloc`, `man 3 calloc`
- **BSD String Utilities:** Differences between glibc and BSD implementations (`strlcpy`, `strlcat`, `bzero` via `<bsd/string.h>` and `-lbsd`).
- **IEEE Std 1003.1 (POSIX):** Specifications for C standard library functions.
- **GNU Make Manual:** [gnu.org/software/make/manual/](https://www.gnu.org/software/make/manual/)

### Artificial Intelligence Usage
In compliance with 42 curriculum README requirements, AI usage was employed for the following tasks:
- **Documentation & Formatting:** Generating structured Markdown documentation, summarizing function prototypes, and organizing clear reference tables.
- **Edge Case Identification:** Outlining non-standard corner cases for `ft_split` (multiple consecutive delimiters, empty strings) and `ft_calloc` zero-allocation behavior.
- **Makefile Optimization:** Reviewing standard dependency tracking patterns and clean rule dependencies.
