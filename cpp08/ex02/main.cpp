#include <iostream>
#include "MutantStack.hpp"
#include <list>

void test_basic_stack_ops() {
    std::cout << "\n=== Basic Stack Operations ===" << "\n";
    MutantStack<int> ms;

    std::cout << "Empty: " << ms.empty() << "\n";          // 1
    ms.push(42);
    std::cout << "Empty: " << ms.empty() << "\n";          // 0
    std::cout << "Top: " << ms.top() << "\n";              // 42
    std::cout << "Size: " << ms.size() << "\n";            // 1

    ms.push(100);
    ms.push(200);
    std::cout << "Top after 2 pushes: " << ms.top() << "\n"; // 200
    ms.pop();
    std::cout << "Top after pop: " << ms.top() << "\n";    // 100
}

void test_iteration_order() {
    std::cout << "\n=== Iteration Order (bottom to top) ===" << "\n";
    MutantStack<int> ms;

    for (int i = 1; i <= 5; i++)
        ms.push(i * 10);

    // Expected: 10 20 30 40 50
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

void test_reverse_iteration() {
    std::cout << "\n=== Reverse Iteration (top to bottom) ===" << "\n";
    MutantStack<int> ms;

    for (int i = 1; i <= 5; i++)
        ms.push(i * 10);

    // Expected: 50 40 30 20 10
    MutantStack<int>::reverse_iterator it = ms.rbegin();
    MutantStack<int>::reverse_iterator ite = ms.rend();
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "\n";
}

void test_copy_constructor() {
    std::cout << "\n=== Copy Constructor ===" << "\n";
    MutantStack<int> ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);

    MutantStack<int> copy(ms);

    std::cout << "Original top: " << ms.top() << "\n";    // 3
    std::cout << "Copy top: " << copy.top() << "\n";      // 3

    // Mutating copy should not affect original
    copy.push(999);
    std::cout << "Original size: " << ms.size() << "\n";  // 3
    std::cout << "Copy size: " << copy.size() << "\n";    // 4
}

void test_assignment_operator() {
    std::cout << "\n=== Assignment Operator ===" << "\n";
    MutantStack<int> ms;
    ms.push(7);
    ms.push(8);
    ms.push(9);

    MutantStack<int> assigned;
    assigned.push(42); // will be overwritten
    assigned = ms;

    std::cout << "Assigned top: " << assigned.top() << "\n"; // 9
    std::cout << "Assigned size: " << assigned.size() << "\n"; // 3
}

void test_iterator_mutation() {
    std::cout << "\n=== Iterator Mutation ===" << "\n";
    MutantStack<int> ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);

    // Modify elements via iterator
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        *it *= 10;

    // Expected: 10 20 30
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
    std::cout << "Top after mutation: " << ms.top() << "\n"; // 30
}

void test_string_type() {
    std::cout << "\n=== String Type ===" << "\n";
    MutantStack<std::string> ms;

    ms.push("hello");
    ms.push("world");
    ms.push("!");

    for (MutantStack<std::string>::iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n"; // hello world !
}

int main() {
    std::cout << "=== MutantStack test ===" << "\n";
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << "\n";

    mstack.pop();
    std::cout << mstack.size() << "\n";

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    // [...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << "\n";
        ++it;
    }

    std::stack<int> s(mstack);

    std::cout << "\n=== Compare with std::list ===" << "\n";
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << "\n";

    lst.pop_back();
    std::cout << lst.size() << "\n";

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    ++lit;
    --lit;
    while (lit != lite) {
        std::cout << *lit << "\n";
        ++lit;
    }
    test_basic_stack_ops();
    test_iteration_order();
    test_reverse_iteration();
    test_copy_constructor();
    test_assignment_operator();
    test_iterator_mutation();
    test_string_type();
    return 0;
}
