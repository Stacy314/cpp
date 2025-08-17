#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
#include <iostream>
class Brain {
private:
    std::string ideas[100];
public:
    Brain(); Brain(const Brain&); Brain& operator=(const Brain&); ~Brain();
    const std::string& getIdea(int i) const; void setIdea(int i, const std::string& s);
};
#endif