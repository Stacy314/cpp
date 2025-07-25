#pragma once

#include <string>

class Contact
{
  public:
	Contact();
	~Contact();
	void setContact();
	bool isValid() const;
	void displayShort(int index) const;
	void displayFull() const;
	std::string generateCatName();
	bool isAlphaOnly(const std::string& str);
	bool isDigitOnly(const std::string& phoneNumber);
	bool isSpaceOnly(const std::string& str);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	void setFirstName(const std::string &value);
	void setLastName(const std::string &value);
	void setNickname(const std::string &value);
	void setPhoneNumber(const std::string &value);
	void setDarkestSecret(const std::string &value);

  private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
};
