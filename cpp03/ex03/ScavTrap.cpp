#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("noname_scav") {
    _hitPoints = 100; _energyPoints = 50; _attackDamage = 20;
    std::cout << "[ScavTrap] Default ctor: " << _name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100; _energyPoints = 50; _attackDamage = 20;
    std::cout << "[ScavTrap] Ctor(name): " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "[ScavTrap] Copy ctor: " << _name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "[ScavTrap] Copy assign: " << _name << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() { std::cout << "[ScavTrap] Dtor: " << _name << std::endl; }

void ScavTrap::attack(const std::string& target) {
    if (_hitPoints <= 0 || _energyPoints <= 0) { std::cout << "[ScavTrap] " << _name << " can't attack" << std::endl; return; }
    --_energyPoints;
    std::cout << "ScavTrap " << _name << " slashes " << target << " for " << _attackDamage << " damage!" << std::endl;
}

void ScavTrap::guardGate() { std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl; }