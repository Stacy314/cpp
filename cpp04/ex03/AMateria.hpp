#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <string>
#include <iostream>
class ICharacter; // fwd

class AMateria {
protected:
    std::string _type;
public:
    AMateria(const std::string& type);
    AMateria(const AMateria&);
    AMateria& operator=(const AMateria&);
    virtual ~AMateria();

    const std::string& getType() const; // Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};
#endif
