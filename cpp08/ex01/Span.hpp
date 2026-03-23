#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <cstddef>
#include <vector>
#include <climits> 
#include <iostream>
#include <algorithm>

class Span{
public:
    Span(unsigned int n);
    Span(Span const &other);
    Span &operator=(Span const &other);
    ~Span();

    template <typename InputIterator>
    void addRange(InputIterator first, InputIterator last) {
        for (; first != last; ++first)
        {
            if (_numbers.size() >= _maxSize)
                throw std::runtime_error("Span is already full");
            _numbers.push_back(*first);
        }
    }

	void addNumber(int value);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

private:
    unsigned int       _maxSize;
    std::vector<int>   _numbers;
};

#endif
