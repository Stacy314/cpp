#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(const std::string &type) : _type(type) {}

AMateria::AMateria(const AMateria &o) : _type(o._type) {}

AMateria &AMateria::operator=(const AMateria &o) {
	if (this != &o)
		_type = o._type;
	return (*this);
}

AMateria::~AMateria() {}

const std::string &AMateria::getType() const {
	return (_type);
}

void AMateria::use(ICharacter &target) {
	(void)target;
	std::cout << "* uses materia on target *" << std::endl;
}
