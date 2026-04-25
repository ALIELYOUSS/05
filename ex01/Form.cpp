#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("ali"), isSigned(false), gradeToSign(150), gradeToExecute(150){
}

Form::~Form(){
}

Form::Form(std::string n, int gs, int ge) : name(n), isSigned(false), gradeToSign(gs),
    gradeToExecute(ge){
    if (gradeToExecute < 1 || gradeToSign < 1)
        throw GradeTooHighException();
    if (gradeToExecute > 150 || gradeToSign > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned),
    gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){
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
    return "Form grade too low";
}

const char *Form::GradeTooHighException::what() const throw(){
    return "Form grade too high";
}

std::ostream& operator<<(std::ostream& os, const Form& b){
    os << b.getName() << ", form signed: " << (b.isitSigned() ? "yes" : "no")
       << ", sign grade " << b.getGradeToSign()
       << ", execute grade " << b.getGradeToExecute() << ".";
    return os;
}

void Form::beSigned(const Bureaucrat& b){
    if (b.getGrade() <= gradeToSign)
        this->isSigned = true;
    else
        throw Form::GradeTooLowException();
}