#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Alpha");
    a.attack("target_dummy");
    a.takeDamage(3);
    a.beRepaired(2);
    a.takeDamage(20);
    a.attack("no_one");
    a.beRepaired(5);
    return 0;
}