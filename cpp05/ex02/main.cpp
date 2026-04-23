#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
    
    Bureaucrat exec("Exec", 1);
    Bureaucrat mid ("Mid", 11150);
   
    ShrubberyCreationForm sh("home");
    RobotomyRequestForm rb("Major Motoko Kusanagi");
    PresidentialPardonForm pp("Arthur Dent");

	exec.executeForm(sh);
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

	return 0;
}
