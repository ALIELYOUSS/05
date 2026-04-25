#include "ShrubberyCreationForm.hpp"
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default"){
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t) : AForm("ShrubberyCreationForm", 145, 137), target(t){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
    if (this != &other){
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void  ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
    checkExecutionRequirements(executor);
    std::string filename = target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("failed to create shrubbery file");
    file << "     *     \n";
    file << "    ***    \n";
    file << "   *****   \n";
    file << "  *******  \n";
    file << "    | |    \n";
    file.close();
}

