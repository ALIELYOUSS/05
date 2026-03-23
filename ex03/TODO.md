# ex03 TODO (based on current progress)

Goal: finish the Intern exercise by keeping ex02 behavior stable and adding dynamic form creation.

## 1) Carry-over from ex02 (already present)
- [x] `AForm` abstract base class exists with `execute(Bureaucrat const &)` pure virtual.
- [x] Derived forms exist:
  - `ShrubberyCreationForm`
  - `RobotomyRequestForm`
  - `PresidentialPardonForm`
- [x] Each derived `execute` calls `checkExecutionRequirements(executor)`.
- [x] `Bureaucrat::executeForm` calls `form.execute(*this)` and reports success/failure.

## 2) Intern class (status after re-check)
- [x ] In `intern.hpp`, replace `#include "Form.hpp"` with `#include "AForm.hpp"`.
- [x ] In `intern.hpp`, change return type from `Form*` to `AForm*`.
- [x] In `intern.cpp`, canonical form exists:
  - default constructor
  - copy constructor
  - assignment operator
  - destructor
- [x] `makeForm` already maps valid names to concrete forms:
  - "shrubbery creation"
  - "robotomy request"
  - "presidential pardon"
- [x ] In `intern.cpp`, include the correct header name for Linux case-sensitive builds (`intern.hpp` vs `Intern.hpp`).
- [ ] In `intern.cpp`, include concrete form headers used in `makeForm`:
  - `ShrubberyCreationForm.hpp`
  - `RobotomyRequestForm.hpp`
  - `PresidentialPardonForm.hpp`
- [ ] In `intern.cpp`, switch `Form*` function signature to `AForm*`.
- [ ] On success, print `Intern creates <formName>` and return allocated form pointer.
- [ ] On unknown form name, print clear error and return `NULL` (instead of throwing).

## 3) Build integration
- [ ] In `Makefile`, add `intern.cpp` to `FILES` so intern is compiled and linked.
- [ ] Add `intern.hpp` to dependency rule if needed.

## 4) Main tests for ex03
- [ ] In `main.cpp`, add a test using `Intern` to create each valid form name.
- [ ] Sign/execute each created form with suitable bureaucrat grades.
- [ ] Add one invalid name test and verify `NULL` + expected message.
- [ ] Delete each dynamically allocated form to avoid leaks.

## 5) Optional cleanup before evaluation
- [ ] Remove verbose constructor/destructor debug prints if evaluator expects strict output.
- [ ] Review exception names/messages for consistency with subject wording.

## 6) Done criteria
- [ ] `make re` succeeds with `intern.cpp` included.
- [ ] `main` demonstrates all 3 valid intern creations + 1 invalid request.
- [ ] No crashes, no leaks from forms created by `Intern`.