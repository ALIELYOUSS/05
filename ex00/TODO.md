# ex00 TODO (specific steps)

Goal: finish a clean Bureaucrat class with correct grade bounds and clear test output.

## 1) Constructors and invariants
- [ ] In Bureaucrat.cpp, make sure every created object has a valid grade in range 1 to 150.
- [ ] In Bureaucrat.cpp, keep the same checks in the parameter constructor:
  - if grade < 1 throw GradeTooHighException
  - if grade > 150 throw GradeTooLowException
- [ ] In Bureaucrat.cpp, keep incrementGrade and decrementGrade bounds strict:
  - incrementGrade must throw when grade is already 1
  - decrementGrade must throw when grade is already 150

## 2) Class form and method signatures
- [ ] In Bureaucrat.hpp, decide if default constructor is allowed by your subject version.
  - If not allowed: remove declaration from header and definition from Bureaucrat.cpp.
  - If allowed: initialize name and grade to valid defaults.
- [ ] In Bureaucrat.hpp and Bureaucrat.cpp, optionally change getName return type to const std::string& to avoid copies.

## 3) Output cleanup
- [ ] In Bureaucrat.cpp, remove constructor/destructor debug prints if your evaluator compares exact output.
- [ ] In Bureaucrat.cpp, fix typo in assignment log text (asignment -> assignment) if you keep logs.
- [ ] In exceptions what methods, keep message text stable and consistent.

## 4) main.cpp test plan
- [ ] Test A: create Bureaucrat with grade 1 and print.
- [ ] Test B: create Bureaucrat with grade 150 and print.
- [ ] Test C: try grade 0 in constructor and confirm exception catch.
- [ ] Test D: try grade 151 in constructor and confirm exception catch.
- [ ] Test E: call incrementGrade on grade 1 and confirm exception.
- [ ] Test F: call decrementGrade on grade 150 and confirm exception.

## 5) Done criteria
- [ ] make re succeeds.
- [ ] Running the binary shows expected success cases and caught exceptions.
