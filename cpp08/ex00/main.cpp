#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void testDeque(void){
	std::deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

	try {
        std::deque<int>::iterator it = easyfind(dq, 1);
        std::cout << "Found in deque: " << *it << "\n";
        it = easyfind(dq, 100);
        std::cout << "Found in deque: " << *it << "\n";
    } catch (std::exception const &e) {
        std::cout << "Deque: " << e.what() << "\n";
    }
}

static void testVector(void){
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    try {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Found in vector: " << *it << "\n";
        it = easyfind(v, 42);
        std::cout << "Found in vector: " << *it << "\n";
    } catch (std::exception const &e) {
        std::cout << "Vector: " << e.what() << "\n";
    }
}

static void testList(void){
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try {
        std::list<int>::iterator it = easyfind(lst, 2);
        std::cout << "Found in list: " << *it << "\n";
        it = easyfind(lst, -1);
        std::cout << "Found in list: " << *it << "\n";
    } catch (std::exception const &e) {
        std::cout << "List: " << e.what() << "\n";
    }
}

int main(){
	testDeque();
    testVector();
    testList();
    return 0;
}
