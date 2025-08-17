#include "ScavTrap.hpp"

int main() {
    ScavTrap s("Serena");
    s.attack("intruder");
    s.guardGate();
    s.takeDamage(42);
    s.beRepaired(10);
    return 0;
}