#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : totalContacts(0), oldestIndex(0) {}

void PhoneBook::addContact() {
    Contact newContact;
    newContact.setContact();

    if (!newContact.isValid()) {
        std::cout << "Error: All fields must be filled." << std::endl;
        return;
    }

    contacts[oldestIndex] = newContact;
    oldestIndex = (oldestIndex + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;

    std::cout << "Contact added!" << std::endl;
}

void PhoneBook::searchContact() const {
    if (totalContacts == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < totalContacts; ++i) {
        contacts[i].displayShort(i);
    }

    std::cout << "Enter index: ";
    std::string input;
    std::getline(std::cin, input);

    if (input.length() != 1 || input[0] < '0' || input[0] > '7') {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    int index = input[0] - '0';
    if (index >= totalContacts) {
        std::cout << "No contact at this index." << std::endl;
        return;
    }

    contacts[index].displayFull();
}