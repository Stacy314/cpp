#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap("No-name Diamond"), ScavTrap(), FragTrap(), _name("No-name brand") {
    _hitPoints = 100;      // FragTrap
    _energyPoints = 50;    // ScavTrap
    _attackDamage = 30;    // FragTrap
    std::cout << "[DiamondTrap] An unnamed diamond warrior emerges, forged from fragments of legends!\n";
}

DiamondTrap::DiamondTrap(const std::string& name)
: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
    _hitPoints = 100;      // FragTrap
    _energyPoints = 50;    // ScavTrap
    _attackDamage = 30;    // FragTrap
    std::cout << "[DiamondTrap] " << GREEN << _name << RESET
              << " sparkles into existence, combining the best of Scav and Frag!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
: ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name) {
   std::cout << "[DiamondTrap] " << BLUE << _name << RESET
              << " has been flawlessly duplicated — two shining gems now exist!\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src) {
    if (this != &src) {
        ScavTrap::operator=(src);
        FragTrap::operator=(src);
        _name = src._name;
    }
    std::cout << "[DiamondTrap] " << YELLOW << _name << RESET
              << " mirrors the brilliance of another DiamondTrap. Copy complete!\n";
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "[DiamondTrap] " << RED << _name << RESET
              << " shatters into stardust... farewell, shining warrior!\n";
}

void DiamondTrap::whoAmI() {
    std::cout << "[DiamondTrap] I am '" << _name << "' and ClapTrap name is '" << ClapTrap::_name << "'" << std::endl;
}
