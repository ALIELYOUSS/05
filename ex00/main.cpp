#include "Bureaucrat.hpp"

int main(){
    try
    {
        Bureaucrat op("op", 1);
        Bureaucrat po("po", 150);
        po.incrementGrade();
        op.decrementGrade();
        std::cout << op << std::endl;
        std::cout << po << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
}