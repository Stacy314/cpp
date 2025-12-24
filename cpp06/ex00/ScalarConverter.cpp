#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isCharLiteral(std::string const &s) {
    return (s.length() == 1 && !std::isdigit(s[0]));
}

static bool isTooLongNumber(const std::string &s) {
    int digits = 0;
    int i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (; i < (int)s.length(); i++) {
        if (std::isdigit(s[i]))
            digits++;
        else if (s[i] == '.' || s[i] == 'f')
            continue;
        else
            break;
    }
    return digits > 16;
}

static void printFromChar(char c) {
    std::cout << "char: '" << c << "'\n";
    int i = static_cast<int>(c);
    std::cout << "int: " << i << "\n";
    float f = static_cast<float>(c);
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
    double d = static_cast<double>(c);
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
}

static void printFromDouble(double d) {
    if (d != d || d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min()) {
        std::cout << "char: impossible\n";
    } else {
        char c = static_cast<char>(d);
        if (std::isprint(static_cast<unsigned char>(c)))
            std::cout << "char: '" << c << "'\n";
        else
            std::cout << "char: Non displayable\n";
    }
    if (d != d || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) {
        std::cout << "int: impossible\n";
    } else {
        int i = static_cast<int>(d);
        std::cout << "int: " << i << "\n";
    }
    float f = static_cast<float>(d);
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
}

void ScalarConverter::convert(std::string const &literal) {
    if (isCharLiteral(literal)) {
        char c = literal[0];
        printFromChar(c);
        return;
    }
	if (isTooLongNumber(literal)) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }
    char *end = 0;
    double d = std::strtod(literal.c_str(), &end);
    bool hasF = false;
    if (end && *end == 'f' && *(end + 1) == '\0')
        hasF = true;
    if ((end == literal.c_str()) || (end && *end != '\0' && !hasF)){
        // invalid literal
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    if (errno == ERANGE){
        // overflow / underflow in parsing
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }
    printFromDouble(d);
}
