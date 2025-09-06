#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("noname_scav") {
    _hitPoints = 100; _energyPoints = 50; _attackDamage = 20;
    std::cout << "[ScavTrap] A brand-new nameless unit crawls out of the scrapyard!\n";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100; _energyPoints = 50; _attackDamage = 20;
    std::cout << "[ScavTrap] " << GREEN << _name << RESET << " stomps into existence, ready to guard some gates!\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "[ScavTrap] " << BLUE << _name << RESET << " duplicated — two gates guarded for the price of one!\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "[ScavTrap] " << YELLOW << _name << RESET << " just received a fresh software upload from another ScavTrap.\n";

    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "[ScavTrap] " << RED << _name << RESET << " rusts away into a pile of spare bolts. Goodbye!\n";

}

void ScavTrap::attack(const std::string& target) {
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "[ScavTrap] " << _name << " can't attack\n";
        return;
    }
    --_energyPoints;
    std::cout << "[ScavTrap] " << _name << " slashes " << target << " for " << _attackDamage << " damage!\n";
}

void ScavTrap::guardGate() {
    std::cout << "[ScavTrap] " << _name << " is now in Gate keeper mode\n";
}
