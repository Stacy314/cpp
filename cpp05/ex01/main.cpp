#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"


int main() {
Bureaucrat boss("Boss", 1);
Bureaucrat intern("Intern", 150);
Form f1("TopSecret", 10, 20);
std::cout << f1 << std::endl;


intern.signForm(f1); // too low
boss.signForm(f1); // success
std::cout << f1 << std::endl;
return 0;
}
