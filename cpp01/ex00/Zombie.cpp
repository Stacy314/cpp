//#include "Zombie.hpp"
//#include <iostream>

//Zombie::Zombie(std::string name) : name(name) {}

//Zombie::~Zombie() {
//    std::cout << name << " is destroyed" << '\n';
//}

//void Zombie::announce() {
//    std::cout << name << ": BraiiiiiiinnnzzzZ..." << '\n';
//}
#include "Zombie.hpp"
#include <iostream>

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

Zombie::Zombie(std::string name) : name(name) {
    std::cout << GREEN << name << " rises from the grave..." << RESET << '\n';
}

Zombie::~Zombie() {
    std::cout << RED << name << " is destroyed and returns to the void." << RESET << '\n';
}

void Zombie::announce() {
    std::cout << YELLOW << name << ": BraiiiiiiinnnzzzZ..." << RESET << '\n';
}
