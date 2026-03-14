#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
    try
    {
        Bureaucrat op("ilegal bureaucrat", 1);
        ShrubberyCreationForm po;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
}