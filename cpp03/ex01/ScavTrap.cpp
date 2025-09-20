#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("No-name Scav") {
    _hitPoints = 100; _energyPoints = 50; _attackDamage = 20;
    std::cout << "[ScavTrap] A brand-new nameless unit crawls out of the scrapyard!\n";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100; _energyPoints = 50; _attackDamage = 20;
    std::cout << "[ScavTrap] " << GREEN << _name << RESET << " stomps into existence, ready to guard some gates!\n";
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
    std::cout << "[ScavTrap] " << BLUE << _name << RESET << " duplicated — two gates guarded for the price of one!\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
    if (this != &src) {
        ClapTrap::operator=(src);
    }
    std::cout << "[ScavTrap] " << YELLOW << _name << RESET << " just received a fresh software upload from ansrc ScavTrap.\n";
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "[ScavTrap] " << RED << _name << RESET << " rusts away into a pile of spare bolts. Goodbye!\n";

}

void ScavTrap::attack(const std::string& target) {
    if (target == _name){
        std::cerr << "⚠️ ScavTrap " << _name << " initiates SELF-DESTRUCT sequence!\n";
        _hitPoints = 0;
        return;
    }
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cerr << "ScavTrap " << _name << " can't attack\n";
        return;
    }
    if (_attackDamage == 0) {
        std::cerr << "ScavTrap " << _name << " tries to attack " << target
                  << " but deals no damage!\n";
        --_energyPoints;
        return;
    }
    --_energyPoints;
    std::cout << "ScavTrap " << _name << " slashes " << target << " for " << _attackDamage << " damage!\n";
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode\n";
}
