#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string n, int g) : garde(g){
    this->name = n;
    std::cout << "param constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
    std::cout << "copy constructor called\n";
    if (&other != this){
        this->name = other.getName();
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
