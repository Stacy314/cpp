#ifndef HARL_HPP
#define HARL_HPP
#pragma once

#include <string>

class Harl {
public:
    void complain(std::string level);

private:
    void _debug();
    void _info();
    void _warning();
    void _error();
};

#endif
