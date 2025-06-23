#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

typedef std::string field_t;

class Contact {
private:
    field_t _firstName;
    field_t _lastName;
    field_t _nickname;
    field_t _phoneNumber;
    field_t _darkestSecret;

public:
    Contact();
	~Contact();
    void setContact();
    void displayShort(int index) const;
    void displayFull() const;
    bool isValid() const;

};

#endif