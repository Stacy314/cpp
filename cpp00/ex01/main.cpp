#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook phoneBook;
	std::string command;
	std::cout << "Welcome to the CatBook! 😸\n";
	while (std::cin)
	{
		std::cout << "Enter your command 😺 (ADD, SEARCH, EXIT):\n";
		std::getline(std::cin, command);
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")  {
			std::cout << "Goodbye 😿\n";
			return 0;
		}
		else if (std::cin.eof()){
			std::cout << "Seriously? 😾\n";
			return 0;
		}
		else
			std::cerr << "\"" << command << "\"? I have never heard it before. 🙀\n";
	}
}