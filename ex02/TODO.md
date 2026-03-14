# ex02 TODO (specific steps)

Goal: make all concrete forms execute with correct signed/grade checks and subject-like output.

## 1) Fix AForm execution rules (this is the exact change for your question)
- [ x] In AForm.hpp, add a dedicated exception class inside AForm:
  - class FormNotSignedException : public std::exception
  - what message example: "form is not signed"
- [x ] In AForm.cpp, implement FormNotSignedException::what().
- [ x] In AForm.cpp, replace current checkExecutionRequirements logic with this order:
  - if isitSigned() is false -> throw FormNotSignedException
  - if executor.getGrade() > getGradeToExecute() -> throw GradeTooLowException
  - do not use any hardcoded grade values

Why this is correct:
- Each form has its own execute grade (Shrubbery 137, Robotomy 45, Presidential 5).
- checkExecutionRequirements must compare against that form's own gradeToExecute, not fixed numbers.

## 2) Enforce const-correct execute signatures
- [ x] In all derived headers and cpp files, keep this exact signature:
  - void execute(Bureaucrat const &executor) const
- [x ] Files to verify:
  - ShrubberyCreationForm.hpp and ShrubberyCreationForm.cpp
  - RobotomyRequestForm.hpp and RobotomyRequestForm.cpp
  - PresidentialPardonForm.hpp and PresidentialPardonForm.cpp

## 3) Keep derived execute bodies safe
- [x ] At the top of each derived execute, call checkExecutionRequirements(executor).
- [x ] In ShrubberyCreationForm.cpp execute:
  - open target + "_shrubbery"
  - if file.is_open() is false, throw an exception
  - write ASCII tree only after successful open
- [ x] In RobotomyRequestForm.cpp execute:
  - print drill sound
  - use rand() % 2 for 50 percent success/failure output
- [x ] In PresidentialPardonForm.cpp execute:
  - print target pardoned by Zaphod Beeblebrox

## 4) Bureaucrat side behavior
- [x ] In Bureaucrat.cpp signForm:
  - print success/failure message with form name and reason
- [x ] In Bureaucrat.cpp executeForm:
  - call form.execute(*this)
  - print success line if no exception
  - print failure line with exception reason if exception thrown

## 5) Makefile and build hygiene
- [ x] In Makefile, include all required cpp files in FILES:
  - main.cpp
  - Bureaucrat.cpp
  - AForm.cpp
  - ShrubberyCreationForm.cpp
  - RobotomyRequestForm.cpp
  - PresidentialPardonForm.cpp
- [ x] Run make re and confirm zero warnings/errors under -Werror.

## 6) main.cpp test checklist (run in this order)
- [x ] Test A unsigned execute failure:
  - create form
  - call executeForm without signing
  - expect FormNotSignedException path
- [x ] Test B low-grade execute failure:
  - sign form with high-rank bureaucrat
  - execute using low-rank bureaucrat
  - expect GradeTooLowException path
- [ x] Test C success execution:
  - sign and execute with valid grades
  - verify output/file side effect
- [ ] Test D run all 3 forms:
  - Shrubbery writes file
  - Robotomy prints success/failure randomly
  - Presidential prints pardon message

## 7) Done criteria
- [x ] make re succeeds.
- [ ] All four tests above run and show expected behavior.
