#include "DiamondTrap.hpp"

int main() {
    DiamondTrap d("VR-0N1CA");
    std::cout << "\n";

    d.whoAmI();
    d.attack("evil cube");
    d.takeDamage(40);
    d.beRepaired(10);
    std::cout << "\n";

    DiamondTrap e(d);
    std::cout << "\n";

    e.whoAmI();
    e.attack("evil cube");
    std::cout << "\n";

    return 0;
}