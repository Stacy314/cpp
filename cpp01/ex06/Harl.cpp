#include "Harl.hpp"
#include <iostream>

void Harl::_debug() {
    std::cout << "[ DEBUG ]" << '\n';
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << '\n';
}

void Harl::_info() {
    std::cout << "[ INFO ]" << '\n';
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << '\n';
}

void Harl::_warning() {
    std::cout << "[ WARNING ]" << '\n';
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << '\n';
}

void Harl::_error() {
    std::cout << "[ ERROR ]" << '\n';
    std::cout << "This is unacceptable! I want to speak to the manager now." << '\n';
}

void Harl::complain(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*methods[])() = {
        &Harl::_debug,
        &Harl::_info,
        &Harl::_warning,
        &Harl::_error
    };

    for (int i = 0; i < 4; ++i) {
        if (level == levels[i]) {
            (this->*methods[i])();
            return;
        }
    }
}