#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
    try
    {
        Bureaucrat b("John", 40);
        ShrubberyCreationForm form("building");
        b.signForm(form);
        b.executeForm(form);


    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
}