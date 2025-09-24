#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()) {
	std::cout << "[Cat] Default constructor called\n";
}

Cat::Cat(const Cat &o) : Animal(o), brain(new Brain(*o.brain)) {
	std::cout << "[Cat] Copy constructor called\n";
}

Cat &Cat::operator=(const Cat &o) {
	if (this!=&o){ 
		Animal::operator=(o);
	    *brain = *o.brain; 
    } 
	std::cout << "[Cat] Copy assignment operator called\n";
	return *this;
}

Cat::~Cat() {
	delete brain; 
	std::cout << "[Cat] Destructor called\n";
}

void Cat::makeSound() const {
	std::cout << "[Cat] Meow!\n";
}

void Cat::setIdea(int i, const std::string& s) {
	brain->setIdea(i, s);
}

const std::string& Cat::getIdea(int i) const {
	return brain->getIdea(i);
}
