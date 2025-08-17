#include "Zombie.hpp"

int main (int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		std::cout << "Usage: ./zombie\n";
		return 1;
	}
	randomChump("Foo");
	Zombie *zombie = newZombie("Boo");
	if (!zombie)
		return 1;
	delete zombie;
}
