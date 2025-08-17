#include "Cat.hpp"
Cat::Cat() : Animal("Cat"), brain(new Brain()) { std::cout << "[Cat] ctor" << std::endl; }
Cat::Cat(const Cat& o) : Animal(o), brain(new Brain(*o.brain)) { std::cout << "[Cat] copy" << std::endl; }
Cat& Cat::operator=(const Cat& o) { if (this!=&o){ Animal::operator=(o); *brain = *o.brain; } std::cout << "[Cat] assign" << std::endl; return *this; }
Cat::~Cat(){ delete brain; std::cout << "[Cat] dtor" << std::endl; }
void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }