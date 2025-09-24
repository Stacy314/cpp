#include "Brain.hpp"

Brain::Brain() { 
    std::cout << "[Brain] Default constructor called\n";
}

Brain::Brain(const Brain& o) { 
    for (int i=0;i<100;++i) 
        ideas[i]=o.ideas[i];
    std::cout << "[Brain] Copy constructor called\n";
}

Brain& Brain::operator=(const Brain& o) {
    if (this!=&o){ 
        for(int i=0;i<100;++i) 
            ideas[i]=o.ideas[i];
    } 
    std::cout << "[Brain] Copy assignment operator called\n"; 
    return *this;
}

Brain::~Brain(){
    std::cout << "[Brain] Destructor called\n";
}

const std::string& Brain::getIdea(int i) const {
    return ideas[i<0?0:(i>99?99:i)];
}

void Brain::setIdea(int i, const std::string& s) {
    if (i>=0 && i<100) ideas[i]=s;
}
