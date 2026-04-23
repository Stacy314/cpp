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

template <typename Container>
void printAfter(const Container &sorted) {
    std::cout << "After: ";
    for (size_t i = 0; i < sorted.size(); ++i)
        std::cout << sorted[i] << " ";
    std::cout << "\n";
}

template <typename Container>
void insertPendElements(Container &mainChain, const Container &pend, const std::vector<size_t> &order) {
    for (size_t i = 0; i < order.size(); ++i) {
        size_t idx = order[i];
        if (idx == 0 || idx >= pend.size())
            continue;

        size_t insertPos = binarySearch(mainChain, pend[idx], mainChain.size());
        mainChain.insert(mainChain.begin() + insertPos, pend[idx]);
    }
}

#endif
