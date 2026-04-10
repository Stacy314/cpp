#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

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

    void sortVector(std::vector<int> &data);
    void sortDeque(std::deque<int> &data);

    std::vector<int> fordJohnsonVector(const std::vector<int> &data);
    std::deque<int>  fordJohnsonDeque(const std::deque<int> &data);

    std::vector<size_t> buildJacobsthalOrder(size_t n) const;

    size_t binarySearchVector(const std::vector<int> &arr, int value, size_t end) const;
    size_t binarySearchDeque(const std::deque<int> &arr, int value, size_t end) const;

    void printBefore() const;
    void printAfter(const std::vector<int> &sorted) const;
};

#endif
