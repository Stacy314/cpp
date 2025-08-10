#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    FragTrap f("Freddy");
    f.highFivesGuys();
    f.attack("dummy");
    f.takeDamage(12);
    f.beRepaired(5);

    ScavTrap s("Sally");
    s.guardGate();
    return 0;
}