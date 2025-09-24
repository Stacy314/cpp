#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
#include <iostream>

class Brain {
public:
    Brain();
    Brain(const Brain&);
    Brain& operator=(const Brain&);
    ~Brain();

    const std::string& getIdea(int i) const;
    void setIdea(int i, const std::string& s);

    private:
    std::string ideas[100];
};

#endif
