#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string t) : target(t), AForm("ShrubberyCreationForm", 147, 137){
    std::cout << "ShrubberyCrationForm constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm destructor called\n";
}

void  ShrubberyCreationForm::execute(Bureaucrat const & executor){

}
