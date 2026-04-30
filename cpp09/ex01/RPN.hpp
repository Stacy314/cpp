#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <stdexcept>
#include <iostream>

class RPN {
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    int evaluate(const std::string &expression);

private:
	std::list<int> _list;
    void applyOperator(char op);
};

#endif
