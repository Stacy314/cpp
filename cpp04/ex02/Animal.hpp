#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
public:
    Animal();
    Animal(const std::string& t);
    Animal(const Animal&);
    Animal& operator=(const Animal&);
    virtual ~Animal();

    virtual void makeSound() const = 0;
    const std::string getType() const;

protected:
    std::string type;

};

#endif
