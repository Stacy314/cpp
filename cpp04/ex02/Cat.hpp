#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat&);
    Cat& operator=(const Cat&);
    virtual ~Cat();
	
    virtual void makeSound() const;	

    void setIdea(int i, const std::string& s);
    const std::string& getIdea(int i) const;

private:
    Brain* brain;
};

#endif
