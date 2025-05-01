#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

int main() {
    int hordeSize = 5;

    Zombie* horde = zombieHorde(hordeSize, "Zombo");

    if (!horde) {
        std::cerr << "Failed to create horde!" << std::endl;
        return 1;
    }

    std::cout << "\n🧟 ZOMBIE HORDE RISES:\n" << std::endl;

    for (int i = 0; i < hordeSize; ++i) {
        std::cout << "Zombie #" << i + 1 << ": ";
        horde[i].announce();
    }

    std::cout << "\n💀 Clearing the undead...\n" << std::endl;
    delete[] horde;

    return 0;
}
