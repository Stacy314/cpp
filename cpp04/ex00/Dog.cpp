#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "[Dog] Default constructor called\n";
}

Dog::Dog(const Dog &o) : Animal(o) {
	std::cout << "[Dog] Copy constructor called\n";
}

Dog &Dog::operator=(const Dog &o) {
	Animal::operator=(o);
	std::cout << "[Dog] Copy assignment operator called\n";
	return (*this);
}

Dog::~Dog() {
	std::cout << "[Dog] Destructor called\n";
}

void Dog::makeSound() const {
	std::cout << "[Dog] Woof!\n";
}
