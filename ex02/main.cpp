#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(){
    try
    {
        Bureaucrat op("ilegal bureaucrat", 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
}