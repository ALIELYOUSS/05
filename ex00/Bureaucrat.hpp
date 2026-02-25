#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>

class Bureaucrat{
private:
    const std::string name;
    int grade;
public:
    class GradeTooHighException : public std::exception{
    public:
        virtual const char* what() const throw() { return "Grade too high"; }
    };
    class GradeTooLowException : public std::exception{
    public:
        virtual const char* what() const throw() { return "Grade too low"; }
    };
    Bureaucrat();
    Bureaucrat(const std::string n, int g);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& other);
    Bureaucrat(const Bureaucrat& other);
    const std::string getName() const{ return name;};
    int getGrade() const {return grade;};
    void incrementGrade();
    void decrementGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif