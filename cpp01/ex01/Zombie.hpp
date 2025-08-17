#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#pragma once

#include <iostream>

#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

class Zombie {
public:
    Zombie();
    ~Zombie();
    void setName(std::string name);
    void announce();

private:
    std::string name;
};

#endif