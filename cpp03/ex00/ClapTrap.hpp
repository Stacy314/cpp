#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"

class ClapTrap
{
public:
    ClapTrap();
    explicit ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &src);
    ClapTrap &operator=(const ClapTrap &src);
    ~ClapTrap();

    // static const unsigned int kDefaultHP;
    // static const unsigned int kDefaultEP;
    // static const unsigned int kDefaultAttack;

    const std::string& getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;

    void setAttackDamage(unsigned int dmg);
    void setName(const std::string& name);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void printStatus() const;

        //     // допоміжні утиліти
    // static unsigned int saturatingAdd(unsigned int a, unsigned int b);
    // static unsigned int saturatingSub(unsigned int a, unsigned int b);


private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

#endif