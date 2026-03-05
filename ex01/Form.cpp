#include "Form.hpp"

Form::Form() : gradeToExecute(0), gradeToSign(0){
    std::cout << "Form constructor called\n"; 
}

Form::~Form(){
    std::cout << "Form destructor called\n";
}

Form::Form(std::string n, int g, bool s, const int gs, const int ge) : name(n), grade(g), isSigned(s), gradeToSign(gs),
    gradeToExecute(ge){
    std::cout << "Form param constructor called\n";
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : gradeToExecute(getGradeToExecute()), gradeToSign(getGradeToSign()){
    std::cout << "copy constructor called\n";
    this->grade = other.getGrade();
    this->name = other.getName();
    this->isSigned = other.Signed();
}

int Form::getGrade() const{
    return grade;
}

int Form::getGradeToExecute() const{
    return gradeToExecute;
}

int Form::getGradeToSign() const{
    return gradeToSign;
}
std::string Form::getName() const{
    return name;
}

bool Form::Signed() const{
    return isSigned;
}