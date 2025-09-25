#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character : public ICharacter {
private:
    std::string _name;
    AMateria*   _inv[4];
    AMateria*   _floor[16]; // simple storage for dropped materias to avoid leaks
    int         _floorTop;
public:
    Character(const std::string& name);
    Character(const Character&);
    Character& operator=(const Character&);
    ~Character();

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};
#endif
