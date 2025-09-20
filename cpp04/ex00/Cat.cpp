#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "[Cat] ctor" << std::endl;
}

Cat::Cat(const Cat &o) : Animal(o) {
	std::cout << "[Cat] copy" << std::endl;
}

Cat &Cat::operator=(const Cat &o) {
	Animal::operator=(o);
	std::cout << "[Cat] assign" << std::endl;
	return (*this);
}

Cat::~Cat() {
	std::cout << "[Cat] dtor" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
