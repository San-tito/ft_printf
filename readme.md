<div align="center">
<h1 align="center">
<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="100" />
<br></h1>
<h3>◦ HTTPStatus Exception: 429</h3>
<h3>◦ Developed with the software and tools below.</h3>

<p align="center">
<img src="https://img.shields.io/badge/YAML-CB171E.svg?style=flat-square&logo=YAML&logoColor=white" alt="YAML" />
<img src="https://img.shields.io/badge/C-A8B9CC.svg?style=flat-square&logo=C&logoColor=black" alt="C" />
<img src="https://img.shields.io/badge/GitHub%20Actions-2088FF.svg?style=flat-square&logo=GitHub-Actions&logoColor=white" alt="GitHub%20Actions" />
</p>
</div>

---

## 📖 Table of Contents
- [📖 Table of Contents](#-table-of-contents)
- [📍 Overview](#-overview)
- [📦 Features](#-features)
- [📂 repository Structure](#-repository-structure)
- [⚙️ Modules](#modules)
- [🚀 Getting Started](#-getting-started)
    - [🔧 Installation](#-installation)
    - [🤖 Running ](#-running-)
    - [🧪 Tests](#-tests)
- [🛣 Roadmap](#-roadmap)
- [🤝 Contributing](#-contributing)
- [📄 License](#-license)
- [👏 Acknowledgments](#-acknowledgments)

---


## 📍 Overview

HTTPStatus Exception: 429

---

## 📦 Features

HTTPStatus Exception: 429

---


## 📂 Repository Structure

```sh
└── /
    ├── .github/
    │   └── workflows/
    │       └── c.yml
    ├── Makefile
    ├── include/
    │   ├── ft_printf.h
    │   └── ft_printf_bonus.h
    ├── libft/
    │   ├── .github/
    │   │   └── workflows/
    │   ├── Makefile
    │   ├── ft_atoi.c
    │   ├── ft_bzero.c
    │   ├── ft_calloc.c
    │   ├── ft_isalnum.c
    │   ├── ft_isalpha.c
    │   ├── ft_isascii.c
    │   ├── ft_isdigit.c
    │   ├── ft_isprint.c
    │   ├── ft_itoa.c
    │   ├── ft_lstadd_back_bonus.c
    │   ├── ft_lstadd_front_bonus.c
    │   ├── ft_lstclear_bonus.c
    │   ├── ft_lstdelone_bonus.c
    │   ├── ft_lstiter_bonus.c
    │   ├── ft_lstlast_bonus.c
    │   ├── ft_lstmap_bonus.c
    │   ├── ft_lstnew_bonus.c
    │   ├── ft_lstsize_bonus.c
    │   ├── ft_memchr.c
    │   ├── ft_memcmp.c
    │   ├── ft_memcpy.c
    │   ├── ft_memmove.c
    │   ├── ft_memset.c
    │   ├── ft_putchar_fd.c
    │   ├── ft_putendl_fd.c
    │   ├── ft_putnbr_fd.c
    │   ├── ft_putstr_fd.c
    │   ├── ft_split.c
    │   ├── ft_strchr.c
    │   ├── ft_strdup.c
    │   ├── ft_striteri.c
    │   ├── ft_strjoin.c
    │   ├── ft_strlcat.c
    │   ├── ft_strlcpy.c
    │   ├── ft_strlen.c
    │   ├── ft_strmapi.c
    │   ├── ft_strncmp.c
    │   ├── ft_strnstr.c
    │   ├── ft_strrchr.c
    │   ├── ft_strtrim.c
    │   ├── ft_substr.c
    │   ├── ft_tolower.c
    │   ├── ft_toupper.c
    │   └── libft.h
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

| File                    | Summary                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| ---                     | ---                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [Makefile]({file_path}) | This Makefile is responsible for building the library libftprintf.a. It compiles the source files located in the src/ directory and creates object files in the objs/ directory. The Makefile also includes a configuration section where you can set compiler flags and specify the name of the library. It depends on the libft.a library, which is built separately using the Makefile in the libft/ directory. The Makefile supports the following commands: all (build the library), bonus (build the library with bonus features), clean (clean up object files), fclean (clean up object files and the library), and re (clean and rebuild the library). |

</details>

<details closed><summary>Include</summary>

| File                             | Summary                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| ---                              | ---                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [ft_printf.h]({file_path})       | The code is a header file named ft_printf.h located in the include directory. It defines the function ft_printf, which is the main function responsible for formatting and printing output. It includes the libft.h header from the libft directory and the stdarg.h header for variable arguments. The code also defines various constants, handles format and conversion specifiers, provides output and string manipulation functions, and includes utility functions for finding indices and freeing memory.                                                                           |
| [ft_printf_bonus.h]({file_path}) | The code provided is a header file named ft_printf_bonus.h that contains function declarations, structures, and definitions necessary to implement a version of printf in C. It includes the necessary libraries, such as libft.h, and defines some constants and structures. The header file defines the main function ft_printf and several other functions for handling format, output, string manipulation, conversion specifier, and conversion modifier. These functions are used for printing formatted output based on the provided format string and the corresponding arguments. |

</details>

<details closed><summary>Src</summary>

| File                                    | Summary                   |
| ---                                     | ---                       |
| [ft_printf.c]({file_path})              | HTTPStatus Exception: 429 |
| [ft_handle_string.c]({file_path})       | HTTPStatus Exception: 429 |
| [ft_alignment_bonus.c]({file_path})     | HTTPStatus Exception: 429 |
| [ft_handle_format.c]({file_path})       | HTTPStatus Exception: 429 |
| [ft_handle_hex.c]({file_path})          | HTTPStatus Exception: 429 |
| [ft_handle_hex_bonus.c]({file_path})    | HTTPStatus Exception: 429 |
| [ft_handle_number.c]({file_path})       | HTTPStatus Exception: 429 |
| [ft_handle_number_bonus.c]({file_path}) | HTTPStatus Exception: 429 |
| [ft_handle_string_bonus.c]({file_path}) | HTTPStatus Exception: 429 |
| [ft_precision_bonus.c]({file_path})     | HTTPStatus Exception: 429 |
| [ft_printf_bonus.c]({file_path})        | HTTPStatus Exception: 429 |
| [ft_space_sign_bonus.c]({file_path})    | HTTPStatus Exception: 429 |
| [ft_utils.c]({file_path})               | HTTPStatus Exception: 429 |
| [ft_utils_bonus.c]({file_path})         | HTTPStatus Exception: 429 |
| [ft_handle_format_bonus.c]({file_path}) | HTTPStatus Exception: 429 |

</details>

<details closed><summary>Libft</summary>

| File                                   | Summary                   |
| ---                                    | ---                       |
| [Makefile]({file_path})                | HTTPStatus Exception: 429 |
| [ft_atoi.c]({file_path})               | HTTPStatus Exception: 429 |
| [ft_bzero.c]({file_path})              | HTTPStatus Exception: 429 |
| [ft_calloc.c]({file_path})             | HTTPStatus Exception: 429 |
| [ft_isalnum.c]({file_path})            | HTTPStatus Exception: 429 |
| [ft_isalpha.c]({file_path})            | HTTPStatus Exception: 429 |
| [ft_isascii.c]({file_path})            | HTTPStatus Exception: 429 |
| [ft_isdigit.c]({file_path})            | HTTPStatus Exception: 429 |
| [ft_isprint.c]({file_path})            | HTTPStatus Exception: 429 |
| [ft_itoa.c]({file_path})               | HTTPStatus Exception: 429 |
| [ft_lstadd_back_bonus.c]({file_path})  | HTTPStatus Exception: 429 |
| [ft_lstadd_front_bonus.c]({file_path}) | HTTPStatus Exception: 429 |
| [ft_lstclear_bonus.c]({file_path})     | HTTPStatus Exception: 429 |
| [ft_lstdelone_bonus.c]({file_path})    | HTTPStatus Exception: 429 |
| [ft_lstiter_bonus.c]({file_path})      | HTTPStatus Exception: 429 |
| [ft_lstlast_bonus.c]({file_path})      | HTTPStatus Exception: 429 |
| [ft_lstmap_bonus.c]({file_path})       | HTTPStatus Exception: 429 |
| [ft_lstnew_bonus.c]({file_path})       | HTTPStatus Exception: 429 |
| [ft_lstsize_bonus.c]({file_path})      | HTTPStatus Exception: 429 |
| [ft_memchr.c]({file_path})             | HTTPStatus Exception: 429 |
| [ft_memcmp.c]({file_path})             | HTTPStatus Exception: 429 |
| [ft_memcpy.c]({file_path})             | HTTPStatus Exception: 429 |
| [ft_memmove.c]({file_path})            | HTTPStatus Exception: 429 |
| [ft_memset.c]({file_path})             | HTTPStatus Exception: 429 |
| [ft_putchar_fd.c]({file_path})         | HTTPStatus Exception: 429 |
| [ft_putendl_fd.c]({file_path})         | HTTPStatus Exception: 429 |
| [ft_putnbr_fd.c]({file_path})          | HTTPStatus Exception: 429 |
| [ft_putstr_fd.c]({file_path})          | HTTPStatus Exception: 429 |
| [ft_split.c]({file_path})              | HTTPStatus Exception: 429 |
| [ft_strchr.c]({file_path})             | HTTPStatus Exception: 429 |
| [ft_strdup.c]({file_path})             | HTTPStatus Exception: 429 |
| [ft_striteri.c]({file_path})           | HTTPStatus Exception: 429 |
| [ft_strjoin.c]({file_path})            | HTTPStatus Exception: 429 |
| [ft_strlcat.c]({file_path})            | HTTPStatus Exception: 429 |
| [ft_strlcpy.c]({file_path})            | HTTPStatus Exception: 429 |
| [ft_strlen.c]({file_path})             | HTTPStatus Exception: 429 |
| [ft_strmapi.c]({file_path})            | HTTPStatus Exception: 429 |
| [ft_strncmp.c]({file_path})            | HTTPStatus Exception: 429 |
| [ft_strnstr.c]({file_path})            | HTTPStatus Exception: 429 |
| [ft_strrchr.c]({file_path})            | HTTPStatus Exception: 429 |
| [ft_strtrim.c]({file_path})            | HTTPStatus Exception: 429 |
| [ft_substr.c]({file_path})             | HTTPStatus Exception: 429 |
| [ft_tolower.c]({file_path})            | HTTPStatus Exception: 429 |
| [ft_toupper.c]({file_path})            | HTTPStatus Exception: 429 |
| [libft.h]({file_path})                 | HTTPStatus Exception: 429 |

</details>

<details closed><summary>Workflows</summary>

| File                 | Summary                   |
| ---                  | ---                       |
| [c.yml]({file_path}) | HTTPStatus Exception: 429 |
| [c.yml]({file_path}) | HTTPStatus Exception: 429 |

</details>

---

## 🚀 Getting Started

***Dependencies***

Please ensure you have the following dependencies installed on your system:

`- ℹ️ Dependency 1`

`- ℹ️ Dependency 2`

`- ℹ️ ...`

### 🔧 Installation

1. Clone the  repository:
```sh
git clone ../
```

2. Change to the project directory:
```sh
cd 
```

3. Install the dependencies:
```sh
gcc -o myapp main.c
```

### 🤖 Running 

```sh
./myapp
```

### 🧪 Tests
```sh
/* No common unit test framework in C */
```

---


## 🛣 Project Roadmap

> - [X] `ℹ️  Task 1: Implement X`
> - [ ] `ℹ️  Task 2: Implement Y`
> - [ ] `ℹ️ ...`


---

## 🤝 Contributing

Contributions are welcome! Here are several ways you can contribute:

- **[Submit Pull Requests](https://github.com/local//blob/main/CONTRIBUTING.md)**: Review open PRs, and submit your own PRs.
- **[Join the Discussions](https://github.com/local//discussions)**: Share your insights, provide feedback, or ask questions.
- **[Report Issues](https://github.com/local//issues)**: Submit bugs found or log feature requests for LOCAL.

#### *Contributing Guidelines*

<details closed>
<summary>Click to expand</summary>

1. **Fork the Repository**: Start by forking the project repository to your GitHub account.
2. **Clone Locally**: Clone the forked repository to your local machine using a Git client.
   ```sh
   git clone <your-forked-repo-url>
   ```
3. **Create a New Branch**: Always work on a new branch, giving it a descriptive name.
   ```sh
   git checkout -b new-feature-x
   ```
4. **Make Your Changes**: Develop and test your changes locally.
5. **Commit Your Changes**: Commit with a clear and concise message describing your updates.
   ```sh
   git commit -m 'Implemented new feature x.'
   ```
6. **Push to GitHub**: Push the changes to your forked repository.
   ```sh
   git push origin new-feature-x
   ```
7. **Submit a Pull Request**: Create a PR against the original project repository. Clearly describe the changes and their motivations.

Once your PR is reviewed and approved, it will be merged into the main branch.

</details>

---

## 📄 License


This project is protected under the [SELECT-A-LICENSE](https://choosealicense.com/licenses) License. For more details, refer to the [LICENSE](https://choosealicense.com/licenses/) file.

---

## 👏 Acknowledgments

- List any resources, contributors, inspiration, etc. here.

[**Return**](#Top)

---

