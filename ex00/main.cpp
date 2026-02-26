#include "Bureaucrat.hpp"

int main(){
    try
    {
        Bureaucrat ali("ali", 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}