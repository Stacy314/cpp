#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string _name; // must be same variable name as in ClapTrap? then keep _name
public:
    DiamondTrap();
    explicit DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& src);
    DiamondTrap& operator=(const DiamondTrap& src);
    ~DiamondTrap();

    using ScavTrap::attack; // choose ScavTrap's attack per subject
    void whoAmI();
};

#endif