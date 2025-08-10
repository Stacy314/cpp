#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>
class Animal {
protected:
    std::string type;
public:
    Animal(); Animal(const std::string&); Animal(const Animal&); Animal& operator=(const Animal&);
    virtual ~Animal();
    virtual void makeSound() const = 0; // pure
    std::string getType() const;
};
#endif