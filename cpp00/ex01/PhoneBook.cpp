#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _totalContacts(0), _oldestIndex(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
    Contact newContact;
    newContact.setContact();

    if (!newContact.isValid()) {
        std::cout << "You should fill all fields. 😾\n";
        return;
    }
    _contacts[_oldestIndex] = newContact;
    _oldestIndex = (_oldestIndex + 1) % 8;
    if (_totalContacts < 8)
        _totalContacts++;
    std::cout << "The cat added! 😻\n";
}

void PhoneBook::searchContact() const {
    if (_totalContacts == 0) {
        std::cout << "CatBook is empty. 😿\n";
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname\n";
	std::cout << std::string(44, '-') << '\n';
    for (int i = 0; i < _totalContacts; ++i) {
        _contacts[i].displayShort(i);
    }
    std::cout << "Enter index: ";
    std::string input;
    std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout << "\nSeriously? 😾\n";
		return;
	}
    if (input.length() != 1 || input[0] < '0' || input[0] > '7') {
        std::cerr << "What are you trying to do? 😾\n";
        return;
    }
    int index = input[0] - '0';
    if (index >= _totalContacts) {
        std::cout << "No cat at this index. 😿\n";
        return;
    }
    _contacts[index].displayFull();
}