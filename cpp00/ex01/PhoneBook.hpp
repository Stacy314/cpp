#pragma once

#include "Contact.hpp"

class PhoneBook {
private:
    Contact _contacts[8];
    int _totalContacts;
    int _oldestIndex;

public:
    PhoneBook();
	~PhoneBook();
    void addContact();
    void searchContact() const;
};