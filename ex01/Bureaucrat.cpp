#include "Bureaucrat.hpp"
#include "Form.hpp"

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

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.getName()){
    std::cout << "copy constructor called\n";
    if (&other != this){
        this->grade = other.getGrade();
    }
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "copy asignment op called\n";
    if (other.getGrade() < 1)
        throw GradeTooHighException();
    if (other.getGrade() > 150)
        throw GradeTooLowException();
    this->grade = other.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "destructor called\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade too Low\n";
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade too High\n";
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
    grade--;
}

void Bureaucrat::decrementGrade(){
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

void Bureaucrat::signaForm(Form& f){
    f.beSigned(*this);
    try {
        f.isitSigned();
        std::cout << name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}

