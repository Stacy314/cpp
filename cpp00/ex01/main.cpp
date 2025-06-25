#include "PhoneBook.hpp"
#include <iostream>
#include <string>

//leak with ctrl + C

int main() {
    PhoneBook phoneBook;
    std::string command;
    while (std::cin) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): \n";
        std::getline(std::cin, command);
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            return 0;
        else
           std::cerr << "Invalid command. Try again.\n";
    }
}