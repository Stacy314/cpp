#ifndef WEAPON_HPP
#define WEAPON_HPP
#pragma once

#include <string>

class Weapon {
public:
    Weapon(std::string type);
    ~Weapon();
    const std::string& getType() const;
    void setType(std::string newType);

private:
    std::string _type;
};

#endif
