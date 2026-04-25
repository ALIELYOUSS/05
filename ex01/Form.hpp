#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool      isSigned;
    const int gradeToSign;
    const int gradeToExecute;
public:
    class GradeTooHighException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    Form();
    Form(std::string n, int gs, int ge);
    Form(const Form& other);
    Form& operator=(const Form &other);
    ~Form();
    int getGradeToExecute() const;
    int getGradeToSign() const;
    std::string getName() const;
    bool isitSigned() const;
    void beSigned(const Bureaucrat& b);
};
std::ostream& operator<<(std::ostream& os, const Form& b);

#endif