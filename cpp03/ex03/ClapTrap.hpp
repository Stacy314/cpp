#pragma once

#include <iostream>
#include <string>

class ClapTrap {
protected: // allow derived classes to access per subject note
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;

public:
    // Orthodox Canonical Form
    ClapTrap();
    explicit ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    // Actions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
