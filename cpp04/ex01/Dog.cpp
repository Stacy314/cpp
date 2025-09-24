#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())  {
	std::cout << "[Dog] Default constructor called\n";
}

Dog::Dog(const Dog &o) : Animal(o), brain(new Brain(*o.brain)) {
	std::cout << "[Dog] Copy constructor called\n";
}

Dog &Dog::operator=(const Dog &o) {
    if (this!=&o){ 
	    Animal::operator=(o);
    	*brain = *o.brain; 
    } 
	std::cout << "[Dog] Copy assignment operator called\n";
	return (*this);
}

Dog::~Dog() {
	delete brain;
	std::cout << "[Dog] Destructor called\n";
}

void Dog::makeSound() const {
	std::cout << "[Dog] Woof!\n";
}

void Dog::setIdea(int i, const std::string& s) {
	brain->setIdea(i, s);
}

const std::string& Dog::getIdea(int i) const {
	return brain->getIdea(i);
}
