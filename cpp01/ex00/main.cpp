//#include "Zombie.hpp"

//Zombie* newZombie(std::string name);
//void randomChump(std::string name);

//int main() {
//    Zombie* heapZombie = newZombie("HeapZ");
//    heapZombie->announce();

//    randomChump("StackZ");

//    delete heapZombie;
//    return 0;
//}


#include "Zombie.hpp"
#include <iostream>

// Прототипи
Zombie* newZombie(std::string name);
void randomChump(std::string name);
std::string getRandomName();

int main() {
    std::cout << "\n🧟 Welcome to ZOMBIE SHOW 198X 🧟‍♀️\n" << std::endl;

    Zombie* heapZombie = newZombie("HeapZ");
    heapZombie->announce();

    std::cout << "\n💥 RANDOM ZOMBIES ON STAGE:\n" << std::endl;
    for (int i = 0; i < 3; i++) {
        randomChump(getRandomName());
    }

    delete heapZombie;

    std::cout << "\n🏁 Show over. The graveyard sleeps again.\n" << std::endl;
    return 0;
}
