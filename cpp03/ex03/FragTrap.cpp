#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("noname_frag") {
    _hitPoints = 100; _energyPoints = 100; _attackDamage = 30;
    std::cout << "[FragTrap] Default ctor: " << _name << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100; _energyPoints = 100; _attackDamage = 30;
    std::cout << "[FragTrap] Ctor(name): " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "[FragTrap] Copy ctor: " << _name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "[FragTrap] Copy assign: " << _name << std::endl;
    return *this;
}

FragTrap::~FragTrap() { std::cout << "[FragTrap] Dtor: " << _name << std::endl; }

void FragTrap::highFivesGuys(void) { std::cout << "FragTrap " << _name << ": High fives, guys!!!" << std::endl; }