#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    Zombie* newZombie = new Zombie(name);
	if (!newZombie){
		std::cerr << "Failed to create zombie" << '\n';
        return NULL;
	}
	newZombie->announce();
	return newZombie;
}
