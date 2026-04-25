#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    std::cout << "Test A: grade 1 signs form grade 1" << std::endl;
    try {
        Bureaucrat high("High", 1);
        Form strict("StrictForm", 1, 150);
        high.signForm(strict);
        std::cout << strict << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "Test B: grade 150 cannot sign form grade 1" << std::endl;
    try {
        Bureaucrat low("Low", 150);
        Form strict("StrictForm", 1, 150);
        low.signForm(strict);
        std::cout << strict << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "Test C: invalid form grade 0" << std::endl;
    try {
        Form invalidHigh("InvalidHigh", 0, 150);
        std::cout << invalidHigh << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "Test D: invalid form grade 151" << std::endl;
    try {
        Form invalidLow("InvalidLow", 151, 150);
        std::cout << invalidLow << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    return 0;
}