#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main(){
    std::srand(std::time(NULL));

    std::cout << "Test A: unsigned execute failure" << std::endl;
    {
        Bureaucrat exec("Executor", 1);
        ShrubberyCreationForm form("unsigned_test");
        exec.executeForm(form);
    }

    std::cout << "Test B: low-grade execute failure" << std::endl;
    {
        Bureaucrat signer("Signer", 1);
        Bureaucrat lowExec("LowExec", 150);
        ShrubberyCreationForm form("low_grade_test");
        signer.signForm(form);
        lowExec.executeForm(form);
    }

    std::cout << "Test C: success execution" << std::endl;
    {
        Bureaucrat chief("Chief", 1);
        ShrubberyCreationForm form("success_test");
        chief.signForm(form);
        chief.executeForm(form);
    }

    std::cout << "Test D: run all 3 forms" << std::endl;
    {
        Bureaucrat chief("Chief", 1);

        ShrubberyCreationForm shrub("garden");
        chief.signForm(shrub);
        chief.executeForm(shrub);

        RobotomyRequestForm robot("Bender");
        chief.signForm(robot);
        chief.executeForm(robot);

        PresidentialPardonForm pardon("Arthur Dent");
        chief.signForm(pardon);
        chief.executeForm(pardon);
    }

    return 0;
}