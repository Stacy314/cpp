#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);
    Form f1("veryImportantDocument", 10, 20);
    std::cout << f1 << "\n";

    intern.signForm(f1);
    boss.signForm(f1);
    std::cout << f1 << "\n";
    return 0;
}
