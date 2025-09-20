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

    virtual void makeSound() const; // virtual in ex00; becomes pure in ex02
    std::string getType() const;

protected:
    std::string type;

};

#endif
