#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string t) : AForm("PresidentialPardonForm", 25, 5), target(t){
    std::cout << "PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm destructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target){
    std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
    std::cout << "PresidentialPardonForm copy assignment operator called\n";
    if (this != &other){
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    checkExecutionRequirements(executor);
    std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}

