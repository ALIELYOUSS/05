#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    try
    {
        Bureaucrat op("ilegal bureaucrat", 1);
        Form corr("legal form", 1, 150);
        op.signaForm(corr);
        std::cout << corr;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
}