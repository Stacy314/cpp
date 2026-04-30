#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : _list(other._list) {}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other)
        _list = other._list;
    return *this;
}

RPN::~RPN() {}

void RPN::applyOperator(char op) {
    if (_list.size() < 2)
        throw std::runtime_error("Error");

    int b = _list.back();
    _list.pop_back();
    int a = _list.back();
    _list.pop_back();

    int mainChain = 0;

    switch (op) {
        case '+':
            mainChain = a + b;
            break;
        case '-':
            mainChain = a - b;
            break;
        case '*':
            mainChain = a * b;
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error");
            mainChain = a / b;
            break;
        default:
            throw std::runtime_error("Error");
    }

    _list.push_back(mainChain);
}

int RPN::evaluate(const std::string &expression) {
    for (std::string::size_type i = 0; i < expression.size(); ++i) {
        char c = expression[i];

        if (std::isspace(static_cast<unsigned char>(c)))
            continue;
        else if (std::isdigit(static_cast<unsigned char>(c))) {
            if (i + 1 < expression.size() &&
                std::isdigit(static_cast<unsigned char>(expression[i + 1])))
                throw std::runtime_error("Error");
            _list.push_back(c - '0');
        } else if ((c == '+' || c == '-' || c == '*' || c == '/') && (std::isspace(static_cast<unsigned char>(expression[i - 1])))) {
            applyOperator(c);
        } else {
            throw std::runtime_error("Error");
        }
    }

    if (_list.size() != 1)
        throw std::runtime_error("Error");

    return _list.back();
}
