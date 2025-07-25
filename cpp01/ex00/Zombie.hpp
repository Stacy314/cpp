#pragma once
//#include <string>
#include <iostream>

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"
class Zombie {
public:
    Zombie(std::string name);
    ~Zombie();
    void announce();

private:
    std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
