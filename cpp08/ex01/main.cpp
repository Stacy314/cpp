#include "Span.hpp"

int main(){
    {
        std::cout << "=== Subject test ===\n";
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << "\n";
        std::cout << sp.longestSpan() << "\n";
    }

    {
        std::cout << "\n=== Big test (10 000 numbers) ===\n";
        unsigned int n = 10000;
        Span big(n);
        for (unsigned int i = 0; i < n; ++i)
            big.addNumber(static_cast<int>(i));
        std::cout << "Shortest span: " << big.shortestSpan() << "\n";
        std::cout << "Longest span: " << big.longestSpan() << "\n";
    }

    {
        std::cout << "\n=== addRange test ===\n";
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        Span sp2(10);
        sp2.addRange(vec.begin(), vec.end());
        std::cout << "Shortest span: " << sp2.shortestSpan() << "\n";
        std::cout << "Longest span: " << sp2.longestSpan() << "\n";
    }
    
    {
        std::cout << "\n=== Overflow ===\n"; //check with 1 number
        Span sp(2);
        try {
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
        } catch (std::exception const &e) {
            std::cout << "Expected exception: " << e.what() << "\n";
        }
    }

    {
        std::cout << "\n=== INT_MAX & INT_MIN ===\n"; //failed with int_min + num (return long)
        Span sp(2);
        sp.addNumber(INT_MIN);
        sp.addNumber(INT_MAX);
        try {
            std::cout << "Longest span: " << sp.longestSpan() << "\n";
        } catch (std::exception const &e) {
            std::cout << "ERROR: " << e.what() << "\n";
        }
    }
    
    return 0;
}
