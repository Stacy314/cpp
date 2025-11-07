#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Intern.hpp"
#include "Bureaucrat.hpp"


int main() {
std::srand(static_cast<unsigned int>(std::time(0)));


Intern someRandomIntern;
AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "Garden");
AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
AForm* nope = someRandomIntern.makeForm("paperwork", "Nobody");


Bureaucrat boss("Boss", 1);


if (rrf) { boss.signForm(*rrf); boss.executeForm(*rrf); }
if (shrub) { boss.signForm(*shrub); boss.executeForm(*shrub); }
if (pardon) { boss.signForm(*pardon); boss.executeForm(*pardon); }


delete rrf;
delete shrub;
delete pardon;
delete nope;


return 0;
}