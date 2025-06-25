#pragma once

#include <string>
class Contact {
public:
    Contact();
	~Contact();
    void setContact();
    bool isValid() const;

	    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    // Setters
    void setFirstName(const std::string& value);
    void setLastName(const std::string& value);
    void setNickname(const std::string& value);
    void setPhoneNumber(const std::string& value);
    void setDarkestSecret(const std::string& value);

    void displayShort(int index) const;
    void displayFull() const;

private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

};
