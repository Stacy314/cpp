#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
    std::cout << RED << name << " has been destroyed." << RESET << '\n';
}

void Zombie::setName(std::string newName) {
    name = newName;
}

void Zombie::announce() {
    std::cout << YELLOW << name << ": BraiiiiiiinnnzzzZ..." << RESET << '\n';
}
