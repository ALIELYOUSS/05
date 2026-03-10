#include "Form.hpp"

Form::Form() : name("ali"), isSigned(false), gradeToSign(150), gradeToExecute(150){
    std::cout << "Form constructor called\n"; 
}

Form::~Form(){
    std::cout << "Form destructor called\n";
}

Form::Form(std::string n, int gs, int ge) : name(n), isSigned(false), gradeToSign(gs),
    gradeToExecute(ge){
    std::cout << "Form param constructor called\n";
    if (gradeToExecute < 1 || gradeToSign < 1)
        throw GradeTooHighException();
    if (gradeToExecute > 150 || gradeToSign > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned),
    gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){
    std::cout << "copy constructor called\n";
}

Form& Form::operator=(const Form &other){
    if (this != &other){
        this->isSigned = other.isitSigned();
    }
    return *this;
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

bool Form::isitSigned() const{
    return isSigned;
}

const char *Form::GradeTooLowException::what() const throw(){
    return "Form grade to sign or to execute too low\n";
}

const char *Form::GradeTooHighException::what() const throw(){
    return "Form grade to sign or to execute too high\n";
}

std::ostream& operator<<(std::ostream& os, const Form& b){
    os << b.getName() << " is the form signed " << b.isitSigned() << " the form s execution grade " << b.getGradeToExecute() << " forms sign grade " << b.getGradeToSign() << "\n";
    return os;
}

void Form::beSigned(const Bureaucrat& b){
    if (b.getGrade() <= gradeToSign)
        this->isSigned = true;
    else
        throw Form::GradeTooLowException();
}