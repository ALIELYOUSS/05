# ex03 TODO (specific steps)

Goal: add Intern factory that creates forms by name and integrates with ex02 classes.

## 1) Create required files
- [ ] Create Intern.hpp
- [ ] Create Intern.cpp
- [ ] Copy or port stable files from ex02:
  - Bureaucrat.hpp/.cpp
  - AForm.hpp/.cpp
  - ShrubberyCreationForm.hpp/.cpp
  - RobotomyRequestForm.hpp/.cpp
  - PresidentialPardonForm.hpp/.cpp
- [ ] Create main.cpp
- [ ] Create Makefile

## 2) Intern class interface
- [ ] In Intern.hpp, declare orthodox canonical form:
  - default constructor
  - copy constructor
  - copy assignment operator
  - destructor
- [ ] In Intern.hpp, declare factory method:
  - AForm* makeForm(const std::string& formName, const std::string& target)

## 3) Intern factory implementation details
- [ ] In Intern.cpp, implement a small mapping table between form names and constructors.
- [ ] Supported input names should be exactly:
  - shrubbery creation
  - robotomy request
  - presidential pardon
- [ ] When match is found:
  - allocate with new
  - print Intern creates <formName>
  - return pointer
- [ ] When no match:
  - print error message for unknown form
  - return NULL

## 4) Makefile content
- [ ] NAME should be something like InternTest or ex03.
- [ ] FILES should include all cpp used by ex03 including Intern.cpp.
- [ ] CXXFLAGS should include -Wall -Wextra -Werror -std=c++98.
- [ ] Add all, clean, fclean, re targets.

## 5) main.cpp required tests
- [ ] Test A valid creation:
  - intern.makeForm("shrubbery creation", "home") returns non-NULL
- [ ] Test B valid creation:
  - intern.makeForm("robotomy request", "bender") returns non-NULL
- [ ] Test C valid creation:
  - intern.makeForm("presidential pardon", "marvin") returns non-NULL
- [ ] Test D invalid creation:
  - intern.makeForm("unknown form", "x") returns NULL and prints clear error
- [ ] For each non-NULL form:
  - sign with valid Bureaucrat
  - execute with valid Bureaucrat
  - delete pointer to avoid leaks

## 6) Done criteria
- [ ] make re succeeds.
- [ ] main demonstrates 3 valid forms + 1 invalid form case.
- [ ] No memory leaks in your own dynamic allocations during normal runs.
