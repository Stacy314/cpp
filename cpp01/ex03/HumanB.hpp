#ifndef HUMANB_HPP
#define HUMANB_HPP
#pragma once

#include <string>

class Weapon;

class HumanB {
public:
	HumanB(const std::string& name);
    ~HumanB();
    void setWeapon(Weapon& weapon);
    void attack() const;

private:
    std::string _name;
    Weapon* _weapon;
};

#endif
