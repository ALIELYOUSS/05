 #include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(50) {
}

Bureaucrat::Bureaucrat(const std::string n, int g) : name(n), grade(g){
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.getName()), grade(other.getGrade()){
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (other.getGrade() < 1)
        throw GradeTooHighException();
    if (other.getGrade() > 150)
        throw GradeTooLowException();
    this->grade = other.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat(){
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade too high";
}

const std::string& Bureaucrat::getName() const{
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
