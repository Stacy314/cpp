#pragma once

#include "Contact.hpp"

class PhoneBook
{
  public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContact() const;

  private:
	Contact _contacts[8];
	int _totalContacts;
	int _oldestIndex;
};