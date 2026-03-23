#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    try {
        Intern someRandomIntern;
        Bureaucrat ceo("CEO", 1);

        AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        AForm* invalid = someRandomIntern.makeForm("tax form", "nobody");

        if (shrubbery) {
            ceo.signForm(*shrubbery);
            ceo.executeForm(*shrubbery);
        }
        if (robotomy) {
            ceo.signForm(*robotomy);
            ceo.executeForm(*robotomy);
        }
        if (pardon) {
            ceo.signForm(*pardon);
            ceo.executeForm(*pardon);
        }
        if (invalid) {
            ceo.signForm(*invalid);
            ceo.executeForm(*invalid);
        }

        delete shrubbery;
        delete robotomy;
        delete pardon;
        delete invalid;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}