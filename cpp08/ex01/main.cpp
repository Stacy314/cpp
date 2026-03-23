#include "Span.hpp"

int main() {

    try{
        std::cout << "=== Subject test ===\n";
        Span sp(5);
        // std::cout << sp.shortestSpan() << "\n";
        sp.addNumber(6);
        // std::cout << sp.longestSpan() << "\n";
        std::cout << "\n";

        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << "\n";
        std::cout << sp.longestSpan() << "\n";



        std::cout << "\n=== Big test (10 000 numbers) ===\n";
        unsigned int n = 10000;
        Span big(n);
        for (unsigned int i = 0; i < n; ++i)
            big.addNumber(static_cast<int>(i));
        std::cout << "Shortest span: " << big.shortestSpan() << "\n";
        std::cout << "Longest span: " << big.longestSpan() << "\n";

        std::cout << "\n=== addRange test ===\n";
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        Span spRange(10);
        spRange.addRange(vec.begin(), vec.end());
        std::cout << "Shortest span: " << spRange.shortestSpan() << "\n";
        std::cout << "Longest span: " << spRange.longestSpan() << "\n";

        std::cout << "\n=== Overflow ===\n";
        Span sp2(2);
            sp2.addNumber(6);
            sp2.addNumber(3);
            // sp2.addNumber(17);

        std::cout << "\n=== INT_MAX & INT_MIN ===\n";
        Span spLimits(2);
        spLimits.addNumber(INT_MIN);
        spLimits.addNumber(INT_MAX);
        std::cout << "Longest span: " << spLimits.longestSpan() << "\n";

    }  catch (std::exception const &e) {
        std::cout << "Exception: " << e.what() << "\n";
        return 1;
    }

    return 0;
}






