#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    int hordeSize = 5;
    Zombie* horde = zombieHorde(hordeSize, "Mikal");
    if (!horde) {
        std::cerr << "Failed to create horde!" << '\n';
        return 1;
    }
    std::cout << "\n🧟 ZOMBIE HORDE RISES:\n" << '\n';
    for (int i = 0; i < hordeSize; ++i) {
        std::cout << "Zombie #" << i + 1 << ": ";
        horde[i].announce();
    }
    std::cout << "\n💀 Clearing the undead...\n" << '\n';
    delete[] horde;
    return 0;
}
