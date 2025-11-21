#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat a("Alice", 2);
        std::cout << a << "\n";
        a.incrementGrade();
        std::cout << a << "\n";
        a.incrementGrade();
        std::cout << "We are out of reach\n";   
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }
    std::cout << "\n";

    try {
        Bureaucrat b("Bob", 151);
        std::cout << "We are out of reach\n"; 
        std::cout << b << "\n";
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }
    std::cout << "\n";
    
    try {
        Bureaucrat c("Carol", 150);
        std::cout << c << "\n";
        c.decrementGrade();
        std::cout << "We are out of reach\n"; 
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }
    return 0;
}
