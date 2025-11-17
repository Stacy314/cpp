#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

static void testVector(void)
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 30);
        std::cout << "Found in vector: " << *it << std::endl;
        it = easyfind(v, 100);
        std::cout << "Found in vector: " << *it << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cout << "Vector: " << e.what() << std::endl;
    }
}

static void testList(void)
{
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 2);
        std::cout << "Found in list: " << *it << std::endl;
        it = easyfind(lst, 42);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cout << "List: " << e.what() << std::endl;
    }
}

int main()
{
    testVector();
    testList();
    return 0;
}
