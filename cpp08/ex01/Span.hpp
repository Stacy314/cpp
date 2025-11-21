#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <cstddef> // size_t

class Span
{
public:
    Span(unsigned int n);
    Span(Span const &other);
    Span &operator=(Span const &other);
    ~Span();

    void addNumber(int value);

    template <typename InputIterator>
    void addRange(InputIterator first, InputIterator last)
    {
        while (first != last)
        {
            if (_numbers.size() >= _maxSize)
                throw std::runtime_error("Span is already full");
            _numbers.push_back(*first);
            ++first;
        }
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

private:
    unsigned int       _maxSize;
    std::vector<int>   _numbers;
};

#endif
