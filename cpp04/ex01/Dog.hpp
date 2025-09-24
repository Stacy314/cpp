#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog&);
    Dog& operator=(const Dog&);
    virtual ~Dog();
	
    virtual void makeSound() const;

    void setIdea(int i, const std::string& s);
    const std::string& getIdea(int i) const;
 
private:
    Brain* brain;
};

#endif
