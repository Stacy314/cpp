#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "[Animal] ctor" << std::endl;
}

Animal::Animal(const std::string &t) : type(t) {
	std::cout << "[Animal] ctor(t)" << std::endl;
}

Animal::Animal(const Animal &o) : type(o.type) {
	std::cout << "[Animal] copy" << std::endl;
}

Animal &Animal::operator=(const Animal &o) {
	if (this != &o)
		type = o.type;
	std::cout << "[Animal] assign" << std::endl;
	return (*this);
}

Animal::~Animal() {
	std::cout << "[Animal] dtor" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "[Animal] ..." << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}
