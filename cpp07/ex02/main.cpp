#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    // Empty array
    Array<int> a;
    std::cout << "a.size() = " << a.size() << "\n";

    // Array with n elements
    Array<int> b(5);
    std::cout << "b.size() = " << b.size() << "\n";
    for (unsigned int i = 0; i < b.size(); ++i)
        b[i] = static_cast<int>(i * 10);

    std::cout << "b contents: ";
    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << b[i] << " ";
    std::cout << "\n";

    // Copy constructor
    Array<int> c(b);
    std::cout << "c (copy of b): ";
    for (unsigned int i = 0; i < c.size(); ++i)
        std::cout << c[i] << " ";
    std::cout << "\n";

    // Modify b to check for deep copy
    if (b.size() > 0)
        b[0] = 999;

    std::cout << "b after modification: ";
    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << b[i] << " ";
    std::cout << "\n";

    std::cout << "c should be unchanged: ";
    for (unsigned int i = 0; i < c.size(); ++i)
        std::cout << c[i] << " ";
    std::cout << "\n";

    // Assignment operator
    Array<std::string> s1(3);
    s1[0] = "hello";
    s1[1] = "array";
    s1[2] = "template";

    Array<std::string> s2;
    s2 = s1;

    std::cout << "s1: ";
    for (unsigned int i = 0; i < s1.size(); ++i)
        std::cout << s1[i] << " ";
    std::cout << "\n";

    std::cout << "s2 (copy): ";
    for (unsigned int i = 0; i < s2.size(); ++i)
        std::cout << s2[i] << " ";
    std::cout << "\n";

    // Exception test
    try {
        std::cout << "Trying out of range access...\n";
        std::cout << b[10] << "\n"; // index out of range
    } catch (std::exception const &e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    return 0;
}

//#include <cstdlib>
//#define MAX_VAL 750

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
