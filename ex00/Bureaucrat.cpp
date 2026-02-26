#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string n, int g) : name(n), grade(g){
    std::cout << "param constructor called\n";
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
    std::cout << "copy constructor called\n";
    if (&other != this){
        this->grade = other.getGrade();
    }
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "copy constructor called\n";
    this->grade = other.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "destructor called\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "exception too Low\n";
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "exception too High\n";
}

const std::string Bureaucrat::getName() const{
    return name;
}

int Bureaucrat::getGrade() const{
    return grade;
}

void Bureaucrat::incrementGrade(){
    if (grade <= 1)
        throw GradeTooHighException();
    if (grade >= 150)
        throw GradeTooLowException();
    else
        grade--;
}

void Bureaucrat::decrementGrade(){
    if (grade <= 1)
        throw GradeTooHighException();
    if (grade >= 150)
        throw GradeTooLowException();
    else
        grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
    os << b.getName() << " Bureaucrat Grade " << b.getGrade() << std::endl;
    return os;
}