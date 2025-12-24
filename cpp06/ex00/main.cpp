#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal>\n"; 
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}



// static void printTest(const std::string &literal)
// {
//     std::cout << "==== \"" << literal << "\" ====\n";
//     ScalarConverter::convert(literal);
//     std::cout << "-----------------------------\n";
// }

// int main()
// {
//     const std::string tests[] = {
//         // // 1. Empty string
//         // "",

//         // // 2. Сhar literals
//         // "a",
//         // "Z",
//         // "f",     
//         // ".",
//         // "+",
//         // "-",
//         // " ",

//         // // 3. Int
//         // "0",             // char: Non displayable
//         // "42",
//         // "-42",
//         // "10",           // char: Non displayable
//         // "2147483647",   
//         // "-2147483648", 
//         // "2147483648",   // int: impossible
//         // "9999999999999999999999",
//         // "-9999999999999999999999",
//         // "1e309",
//         // "1e400",
//         // "2e308",
//         // "-1e309",

//         // // 5. Float 
//         // "0.0f",
//         // "4.2f",
//         // "-4.2f",
//         // "42.0f",
//         // "1.8e308",
        

//         // // 6. Double
//         // "0.0",
//         // "4.2",
//         // "-4.2",
//         // "42.0",

//         // // 7. Pseudo-literals
//         // "nan",
//         // "nanf",
//         // "+inf",
//         // "-inf",
//         // "+inff",
//         // "-inff",

//         // // 8. Impossible to convert
//         // "abc",
//         // "4.2ff",
//         // "nanff",
//         // "++3",
//         // "--2",
//         // "4..2",
//         // ".f"
//     };

//     const int count = sizeof(tests) / sizeof(tests[0]);

//     for (int i = 0; i < count; ++i)
//         printTest(tests[i]);

//     return 0;
// }
