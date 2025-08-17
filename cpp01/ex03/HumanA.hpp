#ifndef HUMANA_HPP
#define HUMANA_HPP
#pragma once

#include <string>

class Weapon;

class HumanA {
public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();
    void attack() const;

private:
    std::string _name;
    Weapon& _weapon;
};

#endif
