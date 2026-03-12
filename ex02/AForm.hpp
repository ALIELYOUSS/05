#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class AForm
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
    AForm();
    AForm(std::string n, int gs, int ge);
    AForm(const AForm& other);
    AForm& operator=(const AForm &other);
    virtual ~AForm();
    int getGradeToExecute() const;
    int getGradeToSign() const;
    std::string getName() const;
    bool isitSigned() const;
    void beSigned(const Bureaucrat& b);
    void checkExecutionRequirements(Bureaucrat const & executor) const;
    virtual void execute(Bureaucrat const & executor) const = 0;
};
std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif