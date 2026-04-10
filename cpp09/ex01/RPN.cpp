#include "RPN.hpp"
#include <stdexcept>
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN() {}

void RPN::applyOperator(char op) {
    if (_stack.size() < 2)
        throw std::runtime_error("Error");

    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();

    int result = 0;

    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error");
            result = a / b;
            break;
        default:
            throw std::runtime_error("Error");
    }

    _stack.push(result);
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
            _stack.push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            applyOperator(c);
        } else {
            throw std::runtime_error("Error");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.top();
}
