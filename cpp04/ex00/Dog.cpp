#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "[Dog] ctor" << std::endl;
}

Dog::Dog(const Dog &o) : Animal(o) {
	std::cout << "[Dog] copy" << std::endl;
}

Dog &Dog::operator=(const Dog &o) {
	Animal::operator=(o);
	std::cout << "[Dog] assign" << std::endl;
	return (*this);
}

Dog::~Dog() {
	std::cout << "[Dog] dtor" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}