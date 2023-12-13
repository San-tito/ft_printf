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

► INSERT-TEXT

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
| [Makefile](https://github.com/San-tito/ft_printf/blob/main/Makefile) | ► INSERT-TEXT |

</details>

<details closed><summary>Src</summary>

| File                                                                                                     | Summary       |
| ---                                                                                                      | ---           |
| [ft_utils_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_utils_bonus.c)                 | ► INSERT-TEXT |
| [ft_utils.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_utils.c)                             | ► INSERT-TEXT |
| [ft_space_sign_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_space_sign_bonus.c)       | ► INSERT-TEXT |
| [ft_printf_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_printf_bonus.c)               | ► INSERT-TEXT |
| [ft_printf.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_printf.c)                           | ► INSERT-TEXT |
| [ft_precision_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_precision_bonus.c)         | ► INSERT-TEXT |
| [ft_handle_string_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_handle_string_bonus.c) | ► INSERT-TEXT |
| [ft_handle_string.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_handle_string.c)             | ► INSERT-TEXT |
| [ft_handle_number_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_handle_number_bonus.c) | ► INSERT-TEXT |
| [ft_handle_number.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_handle_number.c)             | ► INSERT-TEXT |
| [ft_handle_hex_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_handle_hex_bonus.c)       | ► INSERT-TEXT |
| [ft_handle_hex.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_handle_hex.c)                   | ► INSERT-TEXT |
| [ft_handle_format_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_handle_format_bonus.c) | ► INSERT-TEXT |
| [ft_handle_format.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_handle_format.c)             | ► INSERT-TEXT |
| [ft_alignment_bonus.c](https://github.com/San-tito/ft_printf/blob/main/src/ft_alignment_bonus.c)         | ► INSERT-TEXT |

</details>

<details closed><summary>Include</summary>

| File                                                                                           | Summary       |
| ---                                                                                            | ---           |
| [ft_printf_bonus.h](https://github.com/San-tito/ft_printf/blob/main/include/ft_printf_bonus.h) | ► INSERT-TEXT |
| [ft_printf.h](https://github.com/San-tito/ft_printf/blob/main/include/ft_printf.h)             | ► INSERT-TEXT |

</details>

---


## 🚀 Getting Started

***Dependencies***

Please ensure you have the following dependencies installed on your system:

- ℹ️ **C Compiler**: You will need a C compiler to build and run the project.

    - Example for GCC (GNU Compiler Collection):
      ```sh
      sudo apt-get install gcc  # Ubuntu
      sudo yum install gcc      # CentOS
      ```


### 🔧 Installation

1. Clone the ft_printf repository:
```sh
git clone https://github.com/San-tito/ft_printf
```

2. Change to the project directory:
```sh
cd ft_printf
```

3. Install the dependencies:
```sh
make
```

### 🤖 Use ft_printf

```sh
libftprintf.a
```

### 🧪 Tests
```sh
/* Not implemented */
```

---


## 🛣 Project Roadmap

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

- List any resources, contributors, inspiration, etc. here.

[**Return**](#Top)

---

