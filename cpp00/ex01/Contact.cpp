#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {}

bool Contact::isValid() const {
    return !firstName.empty() && !lastName.empty() &&
           !nickname.empty() && !phoneNumber.empty() && !darkestSecret.empty();
}

void Contact::setContact() {
    std::cout << "First Name: ";
    std::getline(std::cin, firstName);

    std::cout << "Last Name: ";
    std::getline(std::cin, lastName);

    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);

    std::cout << "Phone Number: ";
    std::getline(std::cin, phoneNumber);

    std::cout << "Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
}

static std::string formatField(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Contact::displayShort(int index) const {
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << formatField(firstName) << "|"
              << std::setw(10) << formatField(lastName) << "|"
              << std::setw(10) << formatField(nickname) << std::endl;
}

void Contact::displayFull() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}