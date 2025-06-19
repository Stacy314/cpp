#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
    PhoneBook phoneBook;
    std::string command;
    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            return 0;
        else
           /* TODO: cerr */std::cout << "Invalid command. Try again.\n";
    }
}