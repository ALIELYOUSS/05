#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP
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
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& other);
    Bureaucrat(const Bureaucrat& other);
    const std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif