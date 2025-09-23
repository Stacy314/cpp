#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <string>
class WrongAnimal
{
  public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &);
	WrongAnimal &operator=(const WrongAnimal &);
	~WrongAnimal();
	
	void makeSound() const; // not virtual on purpose
	std::string getType() const;

protected:
	std::string type;

};

#endif
