#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "Array.tpp"
# include <cstddef>     // for std::size_t
# include <stdexcept>   // for std::out_of_range

template <typename T>
class Array
{
public:
    Array();                    // empty array
    Array(unsigned int n);      // array of n default-initialized elements
    Array(Array const &other);  // copy constructor
    Array &operator=(Array const &other); // assignment
    ~Array();                   // destructor

    T &operator[](unsigned int index);
    T const &operator[](unsigned int index) const;
    unsigned int size() const;

private:
    T*           _data;
    unsigned int _size;
};

#endif
