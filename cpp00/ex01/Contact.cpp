#include "Contact.hpp"
#include <iostream>
#include <iomanip>

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

	if (_firstName.empty() || _lastName.empty() || _nickname.empty() ||
        _phoneNumber.empty() || _darkestSecret.empty()) {
        return;
    }

    setFirstName(_firstName);
    setLastName(_lastName);
    setNickname(_nickname);
    setPhoneNumber(_phoneNumber);
    setDarkestSecret(_darkestSecret);
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
              << std::setw(10) << formatField(_nickname) << '\n';
}

void Contact::displayFull() const {
    std::cout << "First Name: " << _firstName << '\n';
    std::cout << "Last Name: " << _lastName << '\n';
    std::cout << "Nickname: " << _nickname << '\n';
    std::cout << "Phone Number: " << _phoneNumber << '\n';
    std::cout << "Darkest Secret: " << _darkestSecret << '\n';
}


// Getters
std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickname() const { return _nickname; }
std::string Contact::getPhoneNumber() const { return _phoneNumber; }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }

// Setters
void Contact::setFirstName(const std::string& value) { _firstName = value; }
void Contact::setLastName(const std::string& value) { _lastName = value; }
void Contact::setNickname(const std::string& value) { _nickname = value; }
void Contact::setPhoneNumber(const std::string& value) { _phoneNumber = value; }
void Contact::setDarkestSecret(const std::string& value) { _darkestSecret = value; }
