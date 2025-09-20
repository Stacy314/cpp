#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("No-name Frag") {
    _hitPoints = 100; _energyPoints = 100; _attackDamage = 30;
    std::cout << "[FragTrap] A mysterious warrior with no name bursts onto the battlefield!\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100; _energyPoints = 100; _attackDamage = 30;
    std::cout << "[FragTrap] " << GREEN << _name << RESET << " enters the arena, glowing with explosive energy!\n";

}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
    std::cout << "[FragTrap] " << BLUE << _name << RESET << " has been cloned — double the firepower, double the chaos!\n";

}

FragTrap& FragTrap::operator=(const FragTrap& src) {
    if (this != &src) {
        ClapTrap::operator=(src);
    }
    std::cout << "[FragTrap] " << YELLOW << _name << RESET << " just synced battle data with ansrc FragTrap. Ready for more carnage!\n";

    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "[FragTrap] " << RED << _name << RESET << " collapses in a blaze of glory. BOOM! (self-destruct sequence complete)\n";
}

void FragTrap::attack(const std::string& target) {
    if (target == _name){
        std::cerr << "⚠️ [FragTrap] " << _name << " initiates SELF-DESTRUCT sequence!\n";
        _hitPoints = 0;
        return;
    }
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cerr << "[FragTrap] " << _name << " can't attack\n";
        return;
    }
    if (_attackDamage == 0) {
        std::cerr << "[FragTrap] " << _name << " tries to attack " << target
                  << " but deals no damage!\n";
        --_energyPoints;
        return;
    }
    --_energyPoints;
    std::cout << "[FragTrap] " << _name << " unleashes a mighty blast at " << target
              << ", dealing " << _attackDamage << " damage!\n";
}

void FragTrap::highFivesGuys(void) {
    std::cout << "[FragTrap] " << _name << ": High fives, guys!!!\n";
}
