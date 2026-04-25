#include "Bureaucrat.hpp"

int main(){
    std::cout << "Test A: create grade 1" << std::endl;
    try {
        Bureaucrat a("Alice", 1);
        std::cout << a << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "Test B: create grade 150" << std::endl;
    try {
        Bureaucrat b("Bob", 150);
        std::cout << b << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "Test C: create grade 0 (must throw)" << std::endl;
    try {
        Bureaucrat c("Charlie", 0);
        std::cout << c << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "Test D: create grade 151 (must throw)" << std::endl;
    try {
        Bureaucrat d("Diane", 151);
        std::cout << d << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "Test E: increment grade 1 (must throw)" << std::endl;
    try {
        Bureaucrat e("Eve", 1);
        e.incrementGrade();
        std::cout << e << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "Test F: decrement grade 150 (must throw)" << std::endl;
    try {
        Bureaucrat f("Frank", 150);
        f.decrementGrade();
        std::cout << f << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    return 0;
}
