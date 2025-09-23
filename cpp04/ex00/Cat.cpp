#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "[Cat] Default constructor called\n";
}

Cat::Cat(const Cat &o) : Animal(o) {
	std::cout << "[Cat] Copy constructor called\n";
}

Cat &Cat::operator=(const Cat &o) {
	Animal::operator=(o);
	std::cout << "[Cat] Copy assignment operator called\n";
	return (*this);
}

Cat::~Cat() {
	std::cout << "[Cat] Destructor called\n";
}

void Cat::makeSound() const {
	std::cout << "[Cat] Meow!\n";
}
