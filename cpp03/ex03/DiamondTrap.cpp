#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap("noname_clap_name"), ScavTrap(), FragTrap(), _name("noname") {
    // Set stats per subject: HP from FragTrap, EP from ScavTrap, AD from FragTrap
    _hitPoints = 100;      // FragTrap
    _energyPoints = 50;    // ScavTrap
    _attackDamage = 30;    // FragTrap
    std::cout << "[DiamondTrap] Default ctor: name=" << _name
              << ", ClapTrap name=" << ClapTrap::_name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
    _hitPoints = 100;      // FragTrap
    _energyPoints = 50;    // ScavTrap
    _attackDamage = 30;    // FragTrap
    std::cout << "[DiamondTrap] Ctor(name): name=" << _name
              << ", ClapTrap name=" << ClapTrap::_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
: ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name) {
    std::cout << "[DiamondTrap] Copy ctor: name=" << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src) {
    if (this != &src) {
        ScavTrap::operator=(src);
        FragTrap::operator=(src);
        _name = src._name;
    }
    std::cout << "[DiamondTrap] Copy assign: name=" << _name << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "[DiamondTrap] Dtor: name=" << _name << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "[DiamondTrap] I am '" << _name << "' and ClapTrap name is '" << ClapTrap::_name << "'" << std::endl;
}