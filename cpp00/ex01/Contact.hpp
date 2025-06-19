#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

typedef std::string field_t;

class Contact {
private:
    field_t firstName;
    field_t lastName;
    field_t nickname;
    field_t phoneNumber;
    field_t darkestSecret;

public:
    Contact();
    void setContact();
    void displayShort(int index) const;
    void displayFull() const;
    bool isValid() const;
};

#endif