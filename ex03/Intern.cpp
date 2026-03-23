#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    if (formName == "shrubbery creation") {
        std::cout << "Intern creates " << formName << std::endl;
        return new ShrubberyCreationForm(target);
    }
    if (formName == "robotomy request") {
        std::cout << "Intern creates " << formName << std::endl;
        return new RobotomyRequestForm(target);
    }
    if (formName == "presidential pardon") {
        std::cout << "Intern creates " << formName << std::endl;
        return new PresidentialPardonForm(target);
    }
    std::cout << "Intern couldn't create " << formName << std::endl;
    return NULL;
}


