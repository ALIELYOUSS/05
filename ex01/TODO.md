# ex01 TODO (specific steps)

Goal: implement Form signing flow exactly and keep class dependencies clean.

## 1) Naming and signing flow
- [ ] In Bureaucrat.hpp, rename method signaForm to signForm.
- [ ] In Bureaucrat.cpp, rename implementation signaForm to signForm.
- [ ] In main.cpp, replace calls to signaForm with signForm.
- [ ] In Bureaucrat.cpp signForm method:
  - call form.beSigned(*this)
  - on success print: <bureaucrat name> signed <form name>
  - on failure catch exception and print: <bureaucrat name> couldn't sign <form name> because <reason>

## 2) Form grade checks
- [ ] In Form.cpp constructor Form(string, int, int):
  - throw GradeTooHighException if gradeToSign < 1 or gradeToExecute < 1
  - throw GradeTooLowException if gradeToSign > 150 or gradeToExecute > 150
- [ ] In Form.cpp beSigned:
  - if bureaucrat grade <= gradeToSign set isSigned = true
  - else throw Form::GradeTooLowException

## 3) Header dependency cleanup
- [ ] In Form.hpp, remove include of Bureaucrat.hpp.
- [ ] In Form.hpp, add forward declaration: class Bureaucrat;
- [ ] In Form.cpp, include Bureaucrat.hpp before using Bureaucrat methods.

## 4) Optional polish
- [ ] Rename isitSigned to isSigned across header, cpp, and call sites for readability.
- [ ] If evaluator expects exact output, remove constructor/destructor debug prints.

## 5) main.cpp test plan
- [ ] Test A: form with sign grade 1 and bureaucrat grade 1 -> success.
- [ ] Test B: form with sign grade 1 and bureaucrat grade 150 -> failure.
- [ ] Test C: create form with invalid grade 0 -> exception.
- [ ] Test D: create form with invalid grade 151 -> exception.

## 6) Done criteria
- [ ] make re succeeds with no warnings.
- [ ] Output shows one clear success sign case and one clear failure sign case.
