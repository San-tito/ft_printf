<div align="center">
<h1 align="center">
<img src="https://raw.githubusercontent.com/byaliego/42-project-badges/main/badges/ft_printfm.png" width="150" />
<br>Printf</h1>
<h3>◦ Because ft_putnbr() and ft_putstr() aren’t enough</h3>

<p align="center">
<img src="https://img.shields.io/badge/Barcelona-100000?style=flat-square&logo=42&logoColor=white&labelColor=000000&color=000000" alt="42 Barcelona" />
</p>
<img src="https://img.shields.io/github/actions/workflow/status/San-tito/ft_printf/c.yml?style=flat-square" alt="GitHub%20Actions" />
<img src="https://img.shields.io/github/languages/code-size/San-tito/ft_printf?style=flat-square" alt="GitHub code size" />
<img src="https://img.shields.io/github/languages/top/San-tito/ft_printf?style=flat-square" alt="GitHub top language" />
</div>

---

## 📖 Table of Contents
- [📖 Table of Contents](#-table-of-contents)
- [📍 Overview](#-overview)
- [📦 Features](#-features)
- [📂 repository Structure](#-repository-structure)
- [⚙️ Modules](#-modules)
- [🚀 Getting Started](#-getting-started)
    - [🔧 Installation](#-installation)
    - [🤖 Running ft_printf](#-running-ft_printf)
    - [🧪 Tests](#-tests)
- [🛣 Roadmap](#-roadmap)
- [🤝 Contributing](#-contributing)
- [📄 License](#-license)
- [👏 Acknowledgments](#-acknowledgments)

---


## 📍 Overview

The `Printf` project involves reprogramming the printf() function in C, providing a custom version that mimics the behavior of the original printf() from the standard library. The goal is to create a library, libftprintf.a, containing a function named ft_printf(). This function should replicate the functionality of the standard printf() with a focus on handling various conversion specifiers.

---

## 📦 Features

**Printf Functionality**: A custom implementation of the `printf` function.
    
```c
    int ft_printf(const char *format, ...);
```

**Conversion Specifiers Handling**: Mimics the behavior of the original `printf()` with the following conversion specifiers:
- `%c`: Prints a single character.
- `%s`: Prints a string (as defined by the common C convention).
- `%p`: The `void*` pointer argument is printed in hexadecimal format.
- `%d`: Prints a decimal (base 10) number.
- `%i`: Prints an integer in base 10.
- `%u`: Prints an unsigned decimal (base 10) number.
- `%x`: Prints a number in hexadecimal (base 16) lowercase format.
- `%X`: Prints a number in hexadecimal (base 16) uppercase format.
- `%%`: Prints a percent sign.

**Flag Characters**: The character `%` is followed by zero or more of the following flags:
- `#`: The value should be converted to an "alternate form". Variations include:
       - For `x` and `X` conversions, "0x" or "0X" is prepended.
- `0`: The value should be zero-padded. For numeric conversions, the converted value is padded on the left with zeros. If a precision is given, the 0 flag is ignored.
- `-`: The converted value is left-adjusted on the field boundary. 
- ` ` : A blank should be left before a positive number (or empty string) produced by a signed conversion.
- `+`: A sign (`+` or `-`) should always be placed before a number produced by a signed conversion. Overrides a space if both are used.

**Field Width**
An optional decimal digit string (with a nonzero first digit) specifying a minimum field width. If the converted value has fewer characters than the field width, it will be padded with spaces on the left (or right if the left-adjustment flag is given).

**Precision**
An optional precision, in the form of a period (`.`) followed by an optional decimal digit string. If the precision is given as just `.` , the precision is taken to be zero.

**How to Read Flags**: The conversion specification has the following general form:
```c
    % flags width [ . precision ] conversion
```
- `flags`: Zero or more flag characters that modify the normal behavior of the conversion specification.
- `width`: An optional decimal integer specifying the minimum field width. If the normal conversion produces fewer characters than this, the field is padded with spaces to the specified width.
- `.` (precision): An optional precision to specify the number of digits for numeric conversions or the maximum number of characters for string conversions.
- `conversion`: A character that specifies the conversion to be applied.

---

## 📂 Repository Structure

```sh
└── ft_printf/
    ├── Makefile
    ├── include/
    │   ├── ft_printf.h
    │   └── ft_printf_bonus.h
    ├── libft/
    └── src/
        ├── ft_alignment_bonus.c
        ├── ft_handle_format.c
        ├── ft_handle_format_bonus.c
        ├── ft_handle_hex.c
        ├── ft_handle_hex_bonus.c
        ├── ft_handle_number.c
        ├── ft_handle_number_bonus.c
        ├── ft_handle_string.c
        ├── ft_handle_string_bonus.c
        ├── ft_precision_bonus.c
        ├── ft_printf.c
        ├── ft_printf_bonus.c
        ├── ft_space_sign_bonus.c
        ├── ft_utils.c
        └── ft_utils_bonus.c

```

---

## ⚙️ Modules

<details closed><summary>Root</summary>

| File                                                                 | Summary       |
| ---                                                                  | ---           |
| [Makefile](https://github.com/San-tito/ft_printf/blob/main/Makefile) |  Makefile for compiling the library |

</details>

<details closed><summary>Src</summary>

| File                                                                                                     | Summary|
| ---                                                                                                      | ---|
| [ft_utils_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_utils_bonus.c)                 | Utility functions for the bonus version of `ft_printf`.|
| [ft_utils.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_utils.c)                             | Utility functions for the standard version of `ft_printf`.|
| [ft_space_sign_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_space_sign_bonus.c)       | Functions handling space and sign flags for the bonus version of `ft_printf`.|
| [ft_printf_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_printf_bonus.c)               | Main implementation of the bonus version of `ft_printf`.|
| [ft_printf.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_printf.c)                           | Main implementation of the standard version of `ft_printf`.|
| [ft_precision_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_precision_bonus.c)         | Functions handling precision for the bonus version of `ft_printf`.|
| [ft_handle_string_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_handle_string_bonus.c) | Functions handling string conversions for the bonus version of `ft_printf`.|
| [ft_handle_string.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_handle_string.c)             | Functions handling string conversions for the standard version of `ft_printf`.|
| [ft_handle_number_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_handle_number_bonus.c) | Functions handling numeric conversions for the bonus version of `ft_printf`.|
| [ft_handle_number.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_handle_number.c)             | Functions handling numeric conversions for the standard version of `ft_printf`.|
| [ft_handle_hex_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_handle_hex_bonus.c)       | Functions handling hexadecimal conversions for the bonus version of `ft_printf`.|
| [ft_handle_hex.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_handle_hex.c)                   | Functions handling hexadecimal conversions for the standard version of `ft_printf`.|
| [ft_handle_format_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_handle_format_bonus.c) | Functions handling format specifiers for the bonus version of `ft_printf`.|
| [ft_handle_format.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_handle_format.c)             | Functions handling format specifiers for the standard version of `ft_printf`.|
| [ft_alignment_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_alignment_bonus.c)         | Functions handling alignment for the bonus version of `ft_printf`.|

</details>

<details closed><summary>Include</summary>

| File                                                                                           | Summary|
| ---                                                                                            | ---|
| [ft_printf_bonus.h](https://github.com/San-tito/ft_printf/blob/main/include/ft_printf_bonus.h) | Header file for the bonus version of `ft_printf`. Contains declarations for functions, structures, and flags related to the bonus features.                                                   |
| [ft_printf.h](https://github.com/San-tito/ft_printf/blob/main/include/ft_printf.h)             | Header file for the standard version of `ft_printf`. Contains declarations for functions, structures, and flags related to the standard features.                                                 |


</details>

---


## 🚀 Getting Started

### 🔧 Installation

1. Clone the ft_printf repository:
```sh
git clone --recursive https://github.com/San-tito/ft_printf
```

2. Change to the project directory:
```sh
cd ft_printf
```

3. Compile the dependencies:
```sh
make
```

### 🤖 Use ft_printf
Once the library is successfully compiled, you can use it in your projects. Link the `libftprintf.a` file to your program, and include the `ft_printf.h` header in your source files.
To compile your program with ft_printf, use:
```sh
gcc -o my_program my_program.c -L . -lft
```

### 🧪 Tests
```sh
/* Not implemented */
```

---


## 🛣 Roadmap

> - [X] `ℹ️  Task 1: Implement X`
> - [ ] `ℹ️  Task 2: Implement Y`
> - [ ] `ℹ️ ...`


---

## 🤝 Contributing

Contributions are welcome! Here are several ways you can contribute:

- **[Submit Pull Requests](https://github.com/San-tito/ft_printf/blob/main/CONTRIBUTING.md)**: Review open PRs, and submit your own PRs.
- **[Join the Discussions](https://github.com/San-tito/ft_printf/discussions)**: Share your insights, provide feedback, or ask questions.
- **[Report Issues](https://github.com/San-tito/ft_printf/issues)**: Submit bugs found or log feature requests for SAN-TITO.

---

## 📄 License

This project is protected under the [UNLICENSE](https://choosealicense.com/licenses/unlicense) License. For more details, refer to the [LICENSE](LICENSE) file.

---

## 👏 Acknowledgments

- [printf(3) — Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Formatted Output (The GNU C Library)](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html)
- [Table of Output Conversions (The GNU C Library)](https://www.gnu.org/software/libc/manual/html_node/Table-of-Output-Conversions.html)

[**Return**](#Top)

---

