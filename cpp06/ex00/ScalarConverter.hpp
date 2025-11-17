#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>
#include <limits>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();

public:
    static void convert(const std::string& literal);
};

#endif
