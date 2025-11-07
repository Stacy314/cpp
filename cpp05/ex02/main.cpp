#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
std::srand(static_cast<unsigned int>(std::time(0)));


Bureaucrat exec("Exec", 1);
Bureaucrat mid ("Mid", 50);


ShrubberyCreationForm sh("home");
RobotomyRequestForm rb("Bender");
PresidentialPardonForm pp("Arthur");


exec.signForm(sh); exec.executeForm(sh);
mid.signForm(rb); mid.executeForm(rb); // sign OK, exec too low
exec.signForm(rb); exec.executeForm(rb); // exec OK
exec.signForm(pp); exec.executeForm(pp); // needs grade 5 exec


return 0;
}