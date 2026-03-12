#include "AForm.hpp"

AForm::AForm() : name("ali"), isSigned(false), gradeToSign(150), gradeToExecute(150){
    std::cout << "AForm constructor called\n"; 
}

AForm::~AForm(){
    std::cout << "AForm destructor called\n";
}

AForm::AForm(std::string n, int gs, int ge) : name(n), isSigned(false), gradeToSign(gs),
    gradeToExecute(ge){
    std::cout << "AForm param constructor called\n";
    if (gradeToExecute < 1 || gradeToSign < 1)
        throw GradeTooHighException();
    if (gradeToExecute > 150 || gradeToSign > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned),
    gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){
    std::cout << "copy constructor called\n";
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

const char *AForm::GradeTooLowException::what() const throw(){
    return "AForm grade to sign or to execute too low\n";
}

const char *AForm::GradeTooHighException::what() const throw(){
    return "AForm grade to sign or to execute too high\n";
}

std::ostream& operator<<(std::ostream& os, const AForm& b){
    os << b.getName() << " is the AForm signed " << b.isitSigned() << " the AForm s execution grade " << b.getGradeToExecute() << " AForms sign grade " << b.getGradeToSign() << "\n";
    return os;
}

void AForm::beSigned(const Bureaucrat& b){
    if (b.getGrade() <= gradeToSign)
        this->isSigned = true;
    else
        throw AForm::GradeTooLowException();
}