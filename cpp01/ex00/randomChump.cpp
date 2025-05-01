//#include "Zombie.hpp"

//void randomChump(std::string name) {
//    Zombie zombie(name);
//    zombie.announce();
//}

#include "Zombie.hpp"
#include <cstdlib>  // rand()
#include <ctime>    // time()

void randomChump(std::string name) {
    Zombie zombie(name);
    zombie.announce();
}

std::string getRandomName() {
    static const std::string names[] = {
        "Zed", "Rotty", "Chomps", "Gorey", "Skully", "Fester", "Meatbag", "Undy", "Zombo", "Ghoul"
    };
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(0));
        seeded = true;
    }
    int index = std::rand() % (sizeof(names) / sizeof(std::string));
    return names[index];
}
