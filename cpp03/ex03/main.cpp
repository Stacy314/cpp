#include "DiamondTrap.hpp"

int main() {
    DiamondTrap d("Dima");
    d.whoAmI();
    d.attack("evil cube"); // from ScavTrap
    d.takeDamage(40);
    d.beRepaired(10);

    DiamondTrap e(d);
    e.whoAmI();
    e.attack("another cube");
    return 0;
}