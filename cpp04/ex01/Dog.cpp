#include "Dog.hpp"
Dog::Dog() : Animal("Dog"), brain(new Brain()) { std::cout << "[Dog] ctor" << std::endl; }
Dog::Dog(const Dog& o) : Animal(o), brain(new Brain(*o.brain)) { std::cout << "[Dog] copy" << std::endl; }
Dog& Dog::operator=(const Dog& o) { if (this!=&o){ Animal::operator=(o); *brain = *o.brain; } std::cout << "[Dog] assign" << std::endl; return *this; }
Dog::~Dog(){ delete brain; std::cout << "[Dog] dtor" << std::endl; }
void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }