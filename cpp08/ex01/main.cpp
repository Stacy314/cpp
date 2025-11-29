#include <iostream>
#include "Span.hpp"
#include <vector>
#include <cstdlib>

int main(){
    {
        std::cout << "=== Subject test ===" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    {
        std::cout << "\n=== Big test (10 000 numbers) ===" << std::endl;
        unsigned int n = 10000;
        Span big(n);

        for (unsigned int i = 0; i < n; ++i)
            big.addNumber(static_cast<int>(i)); // простий випадок

        std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
        std::cout << "Longest span: " << big.longestSpan() << std::endl;
    }

    {
        std::cout << "\n=== addRange test ===" << std::endl;
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);

        Span sp2(10);
        sp2.addRange(vec.begin(), vec.end());
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    }

    return 0;
}
