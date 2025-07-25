#include "Contact.hpp"
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <cstdlib>

Contact::Contact() {}

Contact::~Contact() {}

bool Contact::isAlphaOnly(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isalpha(str[i])) {
            return false;
        }
    }
	return true;
}

bool Contact::isDigitOnly(const std::string& phoneNumber) {
	if (phoneNumber.empty()) return false;
	for (size_t i = 0; i < phoneNumber.length(); ++i) {
		if (!std::isdigit(phoneNumber[i])) {
			return false;
		}
	}
	return true;
}

bool Contact::isSpaceOnly(const std::string& str) {
	for (size_t i = 0; i < str.length(); ++i) {
		if (!std::isspace(str[i])) {
			return false;
		}
	}
	return true;
} 

bool Contact::isValid() const {
    return !_firstName.empty() && !_lastName.empty() &&
           !_nickname.empty() && !_phoneNumber.empty() && !_darkestSecret.empty();
}

std::string Contact::generateCatName() {
	static const std::string catNames[] = {
		"Whiskers", "Mittens", "Shadow", "Simba", "Lina",
		"Oliver", "Leo", "Bella", "Chloe", "Mickey"
	};
	return catNames[rand() % 10];
}

void Contact::setContact() {
	std::cout << "First Name: ";
    std::getline(std::cin, _firstName);
	if (_firstName.empty() || !isAlphaOnly(_firstName) || isSpaceOnly(_firstName)) {
		std::cerr << "Try " << generateCatName() << ". ";
		return;
    }
    std::cout << "Last Name: ";
    std::getline(std::cin, _lastName);
	if (_lastName.empty() || !isAlphaOnly(_lastName) || isSpaceOnly(_lastName)) {
		std::cerr << "Does your cat have a pedigree? ";
		return;
    }
    std::cout << "Nickname: ";
    std::getline(std::cin, _nickname);
	if (_nickname.empty() || !isAlphaOnly(_nickname) || isSpaceOnly(_nickname)) {
		std::cerr << "You forgot the nickname. Let's call them \"Mysterious Whiskers\"! ";
		return;
    }
    std::cout << "Phone Number: ";
    std::getline(std::cin, _phoneNumber);
	if (_phoneNumber.empty() || !isDigitOnly(_phoneNumber) || isSpaceOnly(_phoneNumber)) {
		std::cerr << "Enter one of the owner's phone numbers here — you know, for emergencies. ";
		return;
    }
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, _darkestSecret);
	if (_darkestSecret.empty() || isSpaceOnly(_darkestSecret)) {
		std::cerr << "Everyone has a secret... even your cat. ";
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
	if (!isValid()) {
		std::cout << "This cat does not exist yet 😼\n";
		return;
	}
    std::cout << "First Name: " << _firstName << '\n';
    std::cout << "Last Name: " << _lastName << '\n';
    std::cout << "Nickname: " << _nickname << '\n';
    std::cout << "Phone Number: " << _phoneNumber << '\n';
    std::cout << "Darkest Secret: " << _darkestSecret << '\n';
}

std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickname() const { return _nickname; }
std::string Contact::getPhoneNumber() const { return _phoneNumber; }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }

void Contact::setFirstName(const std::string& value) { _firstName = value; }
void Contact::setLastName(const std::string& value) { _lastName = value; }
void Contact::setNickname(const std::string& value) { _nickname = value; }
void Contact::setPhoneNumber(const std::string& value) { _phoneNumber = value; }
void Contact::setDarkestSecret(const std::string& value) { _darkestSecret = value; }
