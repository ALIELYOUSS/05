#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    Intern intern;
    Bureaucrat chief("Chief", 1);

    AForm* shrubbery = intern.makeForm("shrubbery creation", "home");
    AForm* robotomy = intern.makeForm("robotomy request", "Bender");
    AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");
    AForm* invalid = intern.makeForm("tax form", "nobody");

    if (shrubbery) {
        chief.signForm(*shrubbery);
        chief.executeForm(*shrubbery);
    }
    if (robotomy) {
        chief.signForm(*robotomy);
        chief.executeForm(*robotomy);
    }
    if (pardon) {
        chief.signForm(*pardon);
        chief.executeForm(*pardon);
    }
    if (!invalid) {
        std::cout << "Invalid form request handled correctly" << std::endl;
    }

    delete shrubbery;
    delete robotomy;
    delete pardon;
    delete invalid;

    return 0;
}