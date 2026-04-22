#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <set>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void run(int argc, char **argv);

private:
    std::vector<int> _vectorData;
    std::deque<int>  _dequeData;

    void parseArguments(int argc, char **argv);

    std::vector<int> fordJohnsonVector(const std::vector<int> &data);
    std::deque<int>  fordJohnsonDeque(const std::deque<int> &data);

    std::vector<size_t> buildJacobsthalOrder(size_t n) const;

    void printBefore() const;
    void printAfter(const std::vector<int> &sorted) const;
};

template <typename Container>
static size_t binarySearch(const Container &arr, int value, size_t end) {
    size_t left = 0;
    size_t right = end;

    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

#endif
