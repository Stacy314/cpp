#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "[Animal] Default constructor called\n";
}

Animal::Animal(const std::string &t) : type(t) {
	std::cout << "[Animal] Constructor(str) called\n";
}

Animal::Animal(const Animal &o) : type(o.type) {
	std::cout << "[Animal] Copy constructor called\n";
}

Animal &Animal::operator=(const Animal &o) {
	if (this != &o)
		type = o.type;
	std::cout << "[Animal] Copy assignment operator called\n";
	return (*this);
}

Animal::~Animal() {
	std::cout << "[Animal] Destructor called\n";
}

void Animal::makeSound() const {
	std::cout << "[Animal] ...\n";
}

const std::string Animal::getType() const {
	return (type);
}
