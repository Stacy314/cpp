#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &o) : AMateria(o) {}

Cure &Cure::operator=(const Cure &o) {
	AMateria::operator=(o);
	return (*this);
}

Cure::~Cure() {}

AMateria *Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
