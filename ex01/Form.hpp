#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
    std::string name;
    bool      isSigned;
    int       grade;
    int const gradeToSign;
    int const gradeToExecute;
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
    Form(std::string n, int g, bool s, const int gs, const int ge);
    Form(const Form& other);
    ~Form();
    int getGradeToExecute() const;
    int getGradeToSign() const;
    int getGrade() const;
    std::string getName() const;
    bool Signed() const;
};

#endif