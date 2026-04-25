#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("ali"), isSigned(false), gradeToSign(150), gradeToExecute(150){
}

AForm::~AForm(){
}

AForm::AForm(std::string n, int gs, int ge) : name(n), isSigned(false), gradeToSign(gs),
    gradeToExecute(ge){
    if (gradeToExecute < 1 || gradeToSign < 1)
        throw GradeTooHighException();
    if (gradeToExecute > 150 || gradeToSign > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned),
    gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){
}

AForm& AForm::operator=(const AForm &other){
    if (this != &other){
        this->isSigned = other.isitSigned();
    }
    return *this;
}

int AForm::getGradeToExecute() const{
    return gradeToExecute;
}

int AForm::getGradeToSign() const{
    return gradeToSign;
}
std::string AForm::getName() const{
    return name;
}

bool AForm::isitSigned() const{
    return isSigned;
}

const char *AForm::FormNotSignedException::what() const throw(){
    return "form is not signed";
}

const char *AForm::GradeTooLowException::what() const throw(){
    return "grade too low";
}

const char *AForm::GradeTooHighException::what() const throw(){
    return "grade too high";
}

std::ostream& operator<<(std::ostream& os, const AForm& b){
    os << b.getName() << ", form signed: " << (b.isitSigned() ? "yes" : "no")
       << ", sign grade " << b.getGradeToSign()
       << ", execute grade " << b.getGradeToExecute() << ".";
    return os;
}

void AForm::beSigned(const Bureaucrat& b){
    if (b.getGrade() <= gradeToSign)
        this->isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

void    AForm::checkExecutionRequirements(const Bureaucrat& executor) const{
    if (!isitSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
};