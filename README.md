# C++ Module 05: Bureaucracy

Solutions for **42's C++ Module 05**, focused on exception handling, class
relationships, form validation, polymorphic execution, and dynamic object
creation in C++98.

## Overview

The module models a bureaucracy in which bureaucrats have grades and forms have
signature and execution requirements. Each exercise extends the previous one:

1. Validate bureaucrat grades and grade changes.
2. Add forms that can be signed by sufficiently senior bureaucrats.
3. Add executable forms with different actions and permissions.
4. Create forms dynamically through an `Intern` factory.

## Exercises

| Directory | Program | Main topic |
| --- | --- | --- |
| `ex00` | `Bureaucrat` | Grade validation and exceptions |
| `ex01` | `Form` | Form signing and permission checks |
| `ex02` | `AForm` | Abstract forms and polymorphic execution |
| `ex03` | `AForm` | Factory-based form creation with `Intern` |

### `ex00` - Bureaucrat

Implements the `Bureaucrat` class with grades from 1, the highest grade, to
150, the lowest grade. Invalid construction and attempts to move beyond either
boundary throw exceptions.

### `ex01` - Form

Introduces `Form`, including a name, signed state, minimum grade to sign, and
minimum grade to execute. `Bureaucrat::signForm` reports whether signing
succeeded or failed.

### `ex02` - AForm and Concrete Forms

Replaces the base form with an abstract `AForm` and adds three concrete forms:

- `ShrubberyCreationForm`: creates a `<target>_shrubbery` file.
- `RobotomyRequestForm`: attempts a randomized robotomy.
- `PresidentialPardonForm`: announces a presidential pardon.

Forms must be signed and executed by bureaucrats with sufficient grades.

### `ex03` - Intern

Adds an `Intern` factory capable of creating the three concrete forms from a
form name:

```text
shrubbery creation
robotomy request
presidential pardon
```

Unknown form names are rejected without creating an object.

## Requirements

- A C++ compiler with C++98 support
- `make`
- Unix-like environment

The exercises use:

```text
c++ -Wall -Wextra -Werror -std=c++98
```

## Build and Run

Each exercise has its own Makefile. Build and run from the exercise directory:

```bash
cd ex00
make
./Bureaucrat
```

The remaining exercises use these executable names:

```bash
cd ex01 && make && ./Form
cd ../ex02 && make && ./AForm
cd ../ex03 && make && ./AForm
```

`ex02` generates shrubbery output files while testing
`ShrubberyCreationForm`; these generated files are runtime artifacts and are
not part of the source tree.

## Makefile Commands

Run these commands from any exercise directory:

```bash
make          # Build the exercise
make clean    # Remove object files
make fclean   # Remove object files and the executable
make re       # Rebuild from scratch
```

To clean all exercises from the repository root:

```bash
for directory in ex00 ex01 ex02 ex03; do make -C "$directory" fclean; done
```

## Project Structure

```text
.
├── ex00/
│   ├── Bureaucrat.cpp
│   ├── Bureaucrat.hpp
│   ├── Makefile
│   └── main.cpp
├── ex01/
│   ├── Bureaucrat.cpp
│   ├── Bureaucrat.hpp
│   ├── Form.cpp
│   ├── Form.hpp
│   ├── Makefile
│   └── main.cpp
├── ex02/
│   ├── AForm.cpp
│   ├── AForm.hpp
│   ├── Bureaucrat.cpp
│   ├── Bureaucrat.hpp
│   ├── Makefile
│   ├── PresidentialPardonForm.cpp
│   ├── PresidentialPardonForm.hpp
│   ├── RobotomyRequestForm.cpp
│   ├── RobotomyRequestForm.hpp
│   ├── ShrubberyCreationForm.cpp
│   ├── ShrubberyCreationForm.hpp
│   └── main.cpp
├── ex03/
│   ├── AForm.cpp
│   ├── AForm.hpp
│   ├── Bureaucrat.cpp
│   ├── Bureaucrat.hpp
│   ├── Intern.cpp
│   ├── Intern.hpp
│   ├── Makefile
│   ├── PresidentialPardonForm.cpp
│   ├── PresidentialPardonForm.hpp
│   ├── RobotomyRequestForm.cpp
│   ├── RobotomyRequestForm.hpp
│   ├── ShrubberyCreationForm.cpp
│   ├── ShrubberyCreationForm.hpp
│   └── main.cpp
└── README.md
```

## C++98 Concepts

This module practices custom exception classes, inheritance, abstract base
classes, virtual functions, polymorphism, object ownership, and the Orthodox
Canonical Form. No external libraries or C++11-and-later features are needed.
