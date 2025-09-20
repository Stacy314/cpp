#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "[WrongCat] ctor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &o) : WrongAnimal(o) {
	std::cout << "[WrongCat] copy" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &o) {
	WrongAnimal::operator=(o);
	std::cout << "[WrongCat] assign" << std::endl;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "[WrongCat] dtor" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "mEoW? (wrong)" << std::endl;
}