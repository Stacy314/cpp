#ifndef WEAPON_HPP //for several .hpp?
#define WEAPON_HPP

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
