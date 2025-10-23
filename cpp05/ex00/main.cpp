#include "Bureaucrat.hpp"


int main() {
    try {
    Bureaucrat a("Alice", 2);
    std::cout << a << "\n";
    a.incrementGrade();
    std::cout << a << "\n";
    a.incrementGrade();
    } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << "\n";
    }

    try {
    Bureaucrat b("Bob", 151);
    std::cout << b << "\n";
    } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << "\n";
    }

    try {
    Bureaucrat c("Carol", 150);
    c.decrementGrade();
    } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << "\n";
    }

    return 0;
}
