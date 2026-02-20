#include "MutantStack.hpp"

// int main() {
//     std::cout << "=== MutantStack test ===" << "\n";
//     MutantStack<int> mstack;

//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << "\n";

//     mstack.pop();
//     std::cout << mstack.size() << "\n";

//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     // [...]
//     mstack.push(0);

//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();

//     ++it;
//     --it;
//     while (it != ite) {
//         std::cout << *it << "\n";
//         ++it;
//     }

//     std::stack<int> s(mstack);

//     std::cout << "\n=== Compare with std::list ===" << "\n";
//     std::list<int> lst;
//     lst.push_back(5);
//     lst.push_back(17);
//     std::cout << lst.back() << "\n";

//     lst.pop_back();
//     std::cout << lst.size() << "\n";

//     lst.push_back(3);
//     lst.push_back(5);
//     lst.push_back(737);
//     lst.push_back(0);

//     std::list<int>::iterator lit = lst.begin();
//     std::list<int>::iterator lite = lst.end();

//     ++lit;
//     --lit;
//     while (lit != lite) {
//         std::cout << *lit << "\n";
//         ++lit;
//     }

//     return 0;
// }


#include <algorithm>
#include <numeric>
#include <iterator>

static void printTitle(const std::string& t) {
    std::cout << "\n=== " << t << " ===\n";
}

template <typename It>
static void printRange(It b, It e, const std::string& label) {
    std::cout << label << ": ";
    for (; b != e; ++b)
        std::cout << *b << " ";
    std::cout << "\n";
}

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
    printTitle("Basic (subject-like)");
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << "\n";

    mstack.pop();
    std::cout << "size after pop: " << mstack.size() << "\n";

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    printRange(mstack.begin(), mstack.end(), "forward iter");

    std::stack<int> s(mstack);
    std::cout << "copied to std::stack ok (size): " << s.size() << "\n";

    // ------------------------------------------------------------

    printTitle("Compare with std::list (subject-like)");
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "list back: " << lst.back() << "\n";

    lst.pop_back();
    std::cout << "list size after pop: " << lst.size() << "\n";

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    printRange(lst.begin(), lst.end(), "list iter");

    // ------------------------------------------------------------

    printTitle("Empty stack edge cases");
    MutantStack<int> empty;
    std::cout << "empty.size(): " << empty.size() << "\n";
    std::cout << "empty.empty(): " << (empty.empty() ? "true" : "false") << "\n";
    // Не викликаємо top()/pop() на пустому — UB.

    // ------------------------------------------------------------

    printTitle("Iterator ops + modify through iterator");
    MutantStack<int> ms;
    ms.push(10);
    ms.push(20);
    ms.push(30);
    ms.push(40);
    ms.push(50);

    {
        MutantStack<int>::iterator it = ms.begin();
        std::cout << "begin: " << *it << "\n";
        ++it;
        std::cout << "after ++: " << *it << "\n";
        --it;
        std::cout << "after --: " << *it << "\n";
    }

    // modify elements
    {
        MutantStack<int>::iterator it = ms.begin();
        MutantStack<int>::iterator ite = ms.end();
        for (; it != ite; ++it)
            *it = *it + 1;
    }
    printRange(ms.begin(), ms.end(), "after +1 each");

    // ------------------------------------------------------------

    printTitle("Const iterator (read-only)");
    const MutantStack<int> cms(ms);
    {
        MutantStack<int>::const_iterator cit = cms.begin();
        MutantStack<int>::const_iterator cite = cms.end();
        std::cout << "const iter: ";
        for (; cit != cite; ++cit)
            std::cout << *cit << " ";
        std::cout << "\n";
        // *cit = 42; // має не компілюватись
    }

    // ------------------------------------------------------------
    // Reverse iterators (вмикай, якщо в твоєму MutantStack вони є)
    // ------------------------------------------------------------
    /*
    printTitle("Reverse iterators");
    {
        MutantStack<int>::reverse_iterator rit = ms.rbegin();
        MutantStack<int>::reverse_iterator rite = ms.rend();
        std::cout << "reverse: ";
        for (; rit != rite; ++rit)
            std::cout << *rit << " ";
        std::cout << "\n";
    }
    */

    // ------------------------------------------------------------

    printTitle("Copy constructor independence");
    MutantStack<int> a;
    a.push(0);
    a.push(1);
    a.push(2);

    MutantStack<int> b(a); // copy
    a.pop();               // change a

    printRange(a.begin(), a.end(), "a (after pop)");
    printRange(b.begin(), b.end(), "b (copy keeps old)");

    // ------------------------------------------------------------

    printTitle("Assignment operator independence");
    MutantStack<int> c;
    c.push(100);
    c.push(200);

    MutantStack<int> d;
    d.push(1);
    d.push(2);
    d.push(3);

    d = c;
    c.push(300);

    printRange(c.begin(), c.end(), "c (after push 300)");
    printRange(d.begin(), d.end(), "d (assigned should not change)");

    // ------------------------------------------------------------

    printTitle("Standard algorithms (C++98): find/accumulate/distance");
    MutantStack<int> alg;
    for (int i = 1; i <= 10; ++i)
        alg.push(i);

    {
        MutantStack<int>::iterator f = std::find(alg.begin(), alg.end(), 7);
        std::cout << "find 7: " << (f != alg.end() ? "found" : "not found") << "\n";
    }

    {
        int sum = std::accumulate(alg.begin(), alg.end(), 0);
        std::cout << "sum 1..10: " << sum << "\n";
    }

    {
        std::cout << "distance(begin,end): "
                  << std::distance(alg.begin(), alg.end()) << "\n";
    }

    // ------------------------------------------------------------

    printTitle("Compare sequence with std::list (C++98-safe)");
    {
        MutantStack<int> mx;
        std::list<int> lx;

        int values[6] = {5, 17, 3, 5, 737, 0};
        for (int i = 0; i < 6; ++i) {
            mx.push(values[i]);
            lx.push_back(values[i]);
        }

        // C++98 std::equal має 3 аргументи: (first1, last1, first2)
        // Тому додатково перевіряємо розміри.
        bool samePrefix = std::equal(mx.begin(), mx.end(), lx.begin());
        bool sameSize = (mx.size() == lx.size());

        std::cout << "same prefix: " << (samePrefix ? "true" : "false") << "\n";
        std::cout << "same size:   " << (sameSize ? "true" : "false") << "\n";
        std::cout << "overall:     " << ((samePrefix && sameSize) ? "true" : "false") << "\n";

        printRange(mx.begin(), mx.end(), "mx");
        printRange(lx.begin(), lx.end(), "lx");
    }

    // ------------------------------------------------------------

    printTitle("Stress-ish push/pop");
    {
        MutantStack<int> stress;
        for (int i = 0; i < 10000; ++i)
            stress.push(i);
        for (int i = 0; i < 9990; ++i)
            stress.pop();

        std::cout << "stress.size(): " << stress.size() << "\n";
        std::cout << "stress.top(): " << stress.top() << "\n"; // очікувано 9
    }

    // ------------------------------------------------------------

    printTitle("Iterator validity after push (informational)");
    {
        MutantStack<int> iv;
        iv.push(1);
        iv.push(2);
        MutantStack<int>::iterator it = iv.begin();
        std::cout << "before push, *it: " << *it << "\n";
        iv.push(3);
        std::cout << "after push, *it:  " << *it << "\n";
        printRange(iv.begin(), iv.end(), "iv");
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