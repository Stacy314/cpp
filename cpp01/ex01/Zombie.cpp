#include "Zombie.hpp"
#include <iostream>

#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

Zombie::Zombie() {}

Zombie::~Zombie() {
    std::cout << RED << name << " has been destroyed." << RESET << std::endl;
}

void Zombie::setName(std::string newName) {
    name = newName;
}

void Zombie::announce() {
    std::cout << YELLOW << name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
