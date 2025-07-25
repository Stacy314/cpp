#include "Zombie.hpp"

int main ()
{
	randomChump("Foo");
	Zombie *zombie = newZombie("Boo");
	if (!zombie)
		return 1;
	delete zombie;
}