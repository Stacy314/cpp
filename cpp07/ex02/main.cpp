#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    // Порожній масив
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl;

    // Масив з n елементів
    Array<int> b(5);
    std::cout << "b.size() = " << b.size() << std::endl;
    for (unsigned int i = 0; i < b.size(); ++i)
        b[i] = static_cast<int>(i * 10);

    std::cout << "b contents: ";
    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    // Копіювання
    Array<int> c(b);
    std::cout << "c (copy of b): ";
    for (unsigned int i = 0; i < c.size(); ++i)
        std::cout << c[i] << " ";
    std::cout << std::endl;

    // Змінимо b, щоб перевірити глибоку копію
    if (b.size() > 0)
        b[0] = 999;

    std::cout << "b after modification: ";
    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    std::cout << "c should be unchanged: ";
    for (unsigned int i = 0; i < c.size(); ++i)
        std::cout << c[i] << " ";
    std::cout << std::endl;

    // Присвоєння
    Array<std::string> s1(3);
    s1[0] = "hello";
    s1[1] = "array";
    s1[2] = "template";

    Array<std::string> s2;
    s2 = s1;

    std::cout << "s1: ";
    for (unsigned int i = 0; i < s1.size(); ++i)
        std::cout << s1[i] << " ";
    std::cout << std::endl;

    std::cout << "s2 (copy): ";
    for (unsigned int i = 0; i < s2.size(); ++i)
        std::cout << s2[i] << " ";
    std::cout << std::endl;

    // Перевірка винятку
    try
    {
        std::cout << "Trying out of range access..." << std::endl;
        std::cout << b[10] << std::endl; // index out of range
    }
    catch (std::exception const &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}






// #include <iostream>
// #include <Array.hpp>

// #define MAX_VAL 750
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