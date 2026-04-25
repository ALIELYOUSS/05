# C++ Module 05 - Daily Progress (2026-04-25)

This repository contains the 42 C++ Module 05 exercises:
- ex00
- ex01
- ex02
- ex03

### ex00 - Bureaucrat
- Completed Bureaucrat grade validation and boundary behavior.
- Cleaned output for evaluator-friendly runs.
- Added/verified tests for:
  - valid grades (1 and 150)
  - invalid constructor grades (0 and 151)
  - increment/decrement boundary exceptions
- Updated TODO to completed status.

### ex01 - Form
- Completed Form signing flow and Bureaucrat::signForm behavior.
- Fixed header dependencies and grade checks.
- Cleaned unnecessary debug output.
- Verified sign success and sign failure scenarios.

### ex02 - AForm + Concrete Forms
- Completed abstract AForm execution/signing checks.
- Completed:
  - ShrubberyCreationForm
  - RobotomyRequestForm
  - PresidentialPardonForm
- Verified unsigned execute failure, low-grade execute failure, and success cases.
- Verified concrete form side effects/messages.

### ex03 - Intern
- Completed Intern::makeForm for:
  - shrubbery creation
  - robotomy request
  - presidential pardon
- Added invalid form-name handling.
- Verified integration with Bureaucrat sign/execute flow.

## Build and Run

Run inside each exercise folder:

```bash
make re
./Bureaucrat   # ex00
./Form         # ex01
./AForm        # ex02, ex03
```

## Notes
- Generated shrubbery files were cleaned from the workspace after verification.

## Status
Daily objective completed and pushed.
