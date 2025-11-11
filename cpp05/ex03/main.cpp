#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Intern.hpp"
#include "Bureaucrat.hpp"


int main() {
    std::srand((unsigned int)(std::time(0)));

    Intern someRandomIntern;
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    AForm* nope = someRandomIntern.makeForm("paperwork", "Nobody");
    std::cout << '\n';

    Bureaucrat boss("Boss", 1);

    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
    }
    std::cout << '\n';

    if (shrub) {
        boss.signForm(*shrub);
        boss.executeForm(*shrub);
    }
    std::cout << '\n';

    if (pardon) {
        boss.signForm(*pardon);
        boss.executeForm(*pardon);
    }
    std::cout << '\n';

    delete rrf;
    delete shrub;
    delete pardon;
    delete nope;

    return 0;
}