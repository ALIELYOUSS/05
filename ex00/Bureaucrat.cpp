#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string n, int g) : name(n), grade(g){
    std::cout << "param constructor called\n";
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

