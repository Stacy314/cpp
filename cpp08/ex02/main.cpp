#include "MutantStack.hpp"

template <typename It>
static void printRange(It b, It e, const std::string& label) {
    std::cout << label << ": ";
    for (; b != e; ++b)
        std::cout << *b << " ";
    std::cout << "\n";
}

void test_iteration_order() {
    std::cout << "\n=== Iteration Order (bottom to top) ===" << "\n";
    MutantStack<int> ms;

    for (int i = 1; i <= 5; i++)
        ms.push(i * 10);

    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

void test_reverse_iteration() {
    std::cout << "\n=== Reverse Iteration (top to bottom) ===" << "\n";
    MutantStack<int> ms;

    for (int i = 1; i <= 5; i++)
        ms.push(i * 10);

    MutantStack<int>::reverse_iterator it = ms.rbegin();
    MutantStack<int>::reverse_iterator ite = ms.rend();
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "\n";
}

void test_iterator_mutation() {
    std::cout << "\n=== Iterator Mutation ===" << "\n";
    MutantStack<int> ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);

    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        *it *= 10;

    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
    std::cout << "Top after mutation: " << ms.top() << "\n";
}

void test_string_type() {
    std::cout << "\n=== String ===" << "\n";
    MutantStack<std::string> ms;

    ms.push("hello");
    ms.push("world");
    ms.push("!");

    for (MutantStack<std::string>::iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

void test_empty() {
	std::cout << "\n=== Empty stack edge cases ===" << "\n";
    MutantStack<int> empty;
    std::cout << "empty.size(): " << empty.size() << "\n";
    std::cout << "empty.empty(): " << (empty.empty() ? "true" : "false") << "\n";
}

void test_iterator_ops() {
    std::cout << "\n=== Iterator operations ===" << "\n";
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
        std::cout << "after Decrement: " << *it << "\n";
        --it;
        std::cout << "after Increment: " << *it << "\n";
    }

    {
        MutantStack<int>::iterator it = ms.begin();
        MutantStack<int>::iterator ite = ms.end();
        for (; it != ite; ++it)
            *it = *it + 1;
    }
    printRange(ms.begin(), ms.end(), "after +1 each");

}

void test_const_it(){
    std::cout << "\n=== Const iterator ===" << "\n";
	MutantStack<int> ms;
    ms.push(10);
    ms.push(20);
    ms.push(30);
    ms.push(40);
    ms.push(50);
    const MutantStack<int> cms(ms);
    {
        MutantStack<int>::const_iterator cit = cms.begin();
        MutantStack<int>::const_iterator cite = cms.end();
        std::cout << "const iter: ";
        for (; cit != cite; ++cit)
            std::cout << *cit << " ";
        std::cout << "\n";
        //*cit = 42; // won't compile
    }
}

void test_copy_const_indep(){
    std::cout << "\n=== Copy constructor independence ===" << "\n";
    MutantStack<int> a;
    a.push(0);
    a.push(1);
    a.push(2);

    MutantStack<int> b(a);
	printRange(a.begin(), a.end(), "a (before pop)");
    a.pop();

    printRange(a.begin(), a.end(), "a (after pop)");
    printRange(b.begin(), b.end(), "b (copy keeps old)");
}

void test_assig_op_indep(){
    std::cout << "\n=== Assignment operator independence ===" << "\n";
    MutantStack<int> c;
    c.push(100);
    c.push(200);
    MutantStack<int> d;
    d.push(1);
    d.push(2);
    d.push(3);
    d = c;
	printRange(c.begin(), c.end(), "c (before push 300)");
    c.push(300);
    printRange(c.begin(), c.end(), "c (after push 300)");
    printRange(d.begin(), d.end(), "d (assigned should not change)");
}

void test_algorithms(){
    std::cout << "\n=== Standard algorithms ===" << "\n";
    MutantStack<int> alg;
    for (int i = 1; i <= 10; ++i)
        alg.push(i);
    {
        MutantStack<int>::iterator f = std::find(alg.begin(), alg.end(), 7);
        std::cout << "find 7: " << (f != alg.end() ? "found" : "not found") << "\n";
    }
    {
        int sum = std::accumulate(alg.begin(), alg.end(), 0);
        std::cout << "Σ1+...+10: " << sum << "\n";
    }
    {
        std::cout << "distance: "
                  << std::distance(alg.begin(), alg.end()) << "\n";
    }
}

void test_stress(){
    std::cout << "\n=== Stress-ish push/pop ===" << "\n";
    {
        MutantStack<int> stress;
        for (int i = 0; i < 10000; ++i)
            stress.push(i);
		std::cout << "stress.size(): " << stress.size() << "\n";
        std::cout << "stress.top(): " << stress.top() << "\n";
        for (int i = 0; i < 9990; ++i)
            stress.pop();
        std::cout << "stress.size(): " << stress.size() << "\n";
        std::cout << "stress.top(): " << stress.top() << "\n";
    }
}

void test_iter_after_push(){
    std::cout << "\n=== Iterator validity after push ===" << "\n";
    MutantStack<int> iv;
    iv.push(1);
    iv.push(2);
    MutantStack<int>::iterator it = iv.begin();
    std::cout << "before push, *it: " << *it << "\n";
    iv.push(3);
    std::cout << "after push, *it:  " << *it << "\n";
    printRange(iv.begin(), iv.end(), "iv");
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

    std::cout << "\n=== Compare with list ===" << "\n";
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
    test_iteration_order();
    test_reverse_iteration();
    test_iterator_mutation();
    test_string_type();
	test_empty();
	test_iterator_ops();
	test_const_it();
	test_copy_const_indep();
	test_assig_op_indep();
	test_algorithms();
	test_stress();
	test_iter_after_push();
    return 0;
}
