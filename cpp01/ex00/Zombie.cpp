#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
    std::cout << GREEN << name << " rises from the grave..." << RESET << '\n';
}

Zombie::~Zombie() {
    std::cout << RED << name << " is destroyed and returns to the void." << RESET << '\n';
}

void Zombie::announce() {
    std::cout << YELLOW << name << ": BraiiiiiiinnnzzzZ..." << RESET << '\n';
}
