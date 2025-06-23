#include "Contact.hpp"
#include <iostream>
#include <iomanip>


// getters and setters (secure way to access private members)

// TODO: ADD -> ctrl+D (remove information) 

Contact::Contact() {}

Contact::~Contact() {}

bool Contact::isValid() const {
    return !_firstName.empty() && !_lastName.empty() &&
           !_nickname.empty() && !_phoneNumber.empty() && !_darkestSecret.empty();
}

void Contact::setContact() {
    std::cout << "First Name: ";
    std::getline(std::cin, _firstName);

    std::cout << "Last Name: ";
    std::getline(std::cin, _lastName);

    std::cout << "Nickname: ";
    std::getline(std::cin, _nickname);

    std::cout << "Phone Number: ";
    std::getline(std::cin, _phoneNumber);

    std::cout << "Darkest Secret: ";
    std::getline(std::cin, _darkestSecret);
}

static std::string formatField(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Contact::displayShort(int index) const {
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << formatField(_firstName) << "|"
              << std::setw(10) << formatField(_lastName) << "|"
              << std::setw(10) << formatField(_nickname) << std::endl;
}

void Contact::displayFull() const {
    std::cout << "First Name: " << _firstName << std::endl;
    std::cout << "Last Name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone Number: " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}