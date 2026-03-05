#include "Bureaucrat.hpp"

int main(){
    try
    {
        Bureaucrat op("op", 1);
        Bureaucrat po("po", 150);
        std::cout << op.getName() << std::endl; 
        std::cout << po.getName() << std::endl;
        po.incrementGrade();
        op.decrementGrade();
        Bureaucrat od("od", 151);
        std::cout << od.getName() << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
}