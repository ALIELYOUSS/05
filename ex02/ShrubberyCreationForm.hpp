#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm{
private:
    std::string target;
public:
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    void execute(Bureaucrat const & executor);
};

#endif