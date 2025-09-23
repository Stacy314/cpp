#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "[WrongAnimal] Default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &o) : type(o.type) {
	std::cout << "[WrongAnimal] Copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &o) {
	if (this != &o)
		type = o.type;
	std::cout << "[WrongAnimal] Copy assignment operator called\n";
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "[WrongAnimal] Destructor called\n";
}

void WrongAnimal::makeSound() const {
	std::cout << "[WrongAnimal] Makes weird noises\n";
}

std::string WrongAnimal::getType() const {
	return (type);
}
