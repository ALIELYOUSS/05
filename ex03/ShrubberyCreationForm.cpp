#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 147, 137), target("default"){
    std::cout << "ShrubberyCrationForm default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t) : AForm("ShrubberyCreationForm", 147, 137), target(t){
    std::cout << "ShrubberyCrationForm constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target){
    std::cout << "ShrubberyCreationForm copy constructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
    std::cout << "ShrubberyCreationForm copy assignment operator called\n";
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
        throw std::runtime_error("Failed to create shrubbery file\n");
    file << "     *     \n";
    file << "    ***    \n";
    file << "   *****   \n";
    file << "  *******  \n";
    file << "    | |    \n";
    file.close();
}

