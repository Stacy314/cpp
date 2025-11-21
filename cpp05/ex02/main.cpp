#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
    std::srand((unsigned int)(std::time(0)));
    
    Bureaucrat exec("Exec", 1);
    Bureaucrat mid ("Mid", 50);
   
    ShrubberyCreationForm sh("home");
    RobotomyRequestForm rb("Major Motoko Kusanagi");
    PresidentialPardonForm pp("Arthur Dent");

    exec.signForm(sh);
    exec.executeForm(sh);
    std::cout << '\n';

    mid.signForm(rb);
    mid.executeForm(rb);
    std::cout << '\n';

    exec.signForm(rb);
    exec.executeForm(rb);
    std::cout << '\n';

    exec.signForm(pp);
    exec.executeForm(pp);
    std::cout << '\n';

    return 0;
}
