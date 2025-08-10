#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _name("noname"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "[ClapTrap] Default ctor: " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "[ClapTrap] Ctor(name): " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    std::cout << "[ClapTrap] Copy ctor: " << _name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "[ClapTrap] Copy assign: " << _name << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "[ClapTrap] Dtor: " << _name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints <= 0) {
        std::cout << "[ClapTrap] " << _name << " can't attack (no HP)" << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "[ClapTrap] " << _name << " can't attack (no energy)" << std::endl;
        return;
    }
    --_energyPoints;
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << "[ClapTrap] " << _name << " is already out (no HP)" << std::endl;
        return;
    }
    int dmg = static_cast<int>(amount);
    _hitPoints -= dmg;
    if (_hitPoints < 0) _hitPoints = 0;
    std::cout << "[ClapTrap] " << _name << " takes " << dmg << " damage (HP=" << _hitPoints << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << "[ClapTrap] " << _name << " can't repair (no HP)" << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "[ClapTrap] " << _name << " can't repair (no energy)" << std::endl;
        return;
    }
    --_energyPoints;
    _hitPoints += static_cast<int>(amount);
    std::cout << "[ClapTrap] " << _name << " repairs for " << amount
              << " (HP=" << _hitPoints << ", EP=" << _energyPoints << ")" << std::endl;
}