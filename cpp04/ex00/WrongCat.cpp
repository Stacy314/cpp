#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "[WrongCat] Default constructor called\n";
}

WrongCat::WrongCat(const WrongCat &o) : WrongAnimal(o) {
	std::cout << "[WrongCat] Copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &o) {
	WrongAnimal::operator=(o);
	std::cout << "[WrongCat] Copy assignment operator called\n";
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "[WrongCat] Destructor called\n";
}

void WrongCat::makeSound() const {
	std::cout << "mEoW? (wrong)\n";
}
