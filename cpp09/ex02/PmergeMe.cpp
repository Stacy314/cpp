#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <set>

//diplacate
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
    : _vectorData(other._vectorData), _dequeData(other._dequeData) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseArguments(int argc, char **argv) {
    std::set<int> seen;

    for (int i = 1; i < argc; ++i) {
        std::string s(argv[i]);
        if (s.empty())
            throw std::runtime_error("Error");

        for (size_t j = 0; j < s.size(); ++j) {
            if (!std::isdigit(static_cast<unsigned char>(s[j])))
                throw std::runtime_error("Error");
        }

        long value = std::strtol(s.c_str(), NULL, 10);
        if (value < 0 || value > 2147483647)
            throw std::runtime_error("Error");

        if (seen.find(static_cast<int>(value)) != seen.end())
            throw std::runtime_error("Error");

        seen.insert(static_cast<int>(value));
        _vectorData.push_back(static_cast<int>(value));
        _dequeData.push_back(static_cast<int>(value));
    }

    if (_vectorData.empty())
        throw std::runtime_error("Error");
}

void PmergeMe::printBefore() const {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vectorData.size(); ++i)
        std::cout << _vectorData[i] << " ";
    std::cout << "\n";
}

void PmergeMe::printAfter(const std::vector<int> &sorted) const {
    std::cout << "After: ";
    for (size_t i = 0; i < sorted.size(); ++i)
        std::cout << sorted[i] << " ";
    std::cout << "\n";
}

std::vector<size_t> PmergeMe::buildJacobsthalOrder(size_t n) const {
    std::vector<size_t> result;
    if (n == 0)
        return result;

    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);

    while (jacob.back() < n) {
        size_t sz = jacob.size();
        jacob.push_back(jacob[sz - 1] + 2 * jacob[sz - 2]);
    }

    std::vector<bool> used(n, false);

    for (size_t i = 2; i < jacob.size(); ++i) {
        size_t start = jacob[i];
        size_t prev = jacob[i - 1];

        if (start > n)
            start = n;

        while (start > prev) {
            --start;
            if (start < n && !used[start]) {
                result.push_back(start);
                used[start] = true;
            }
        }
    }

    for (size_t i = 0; i < n; ++i) {
        if (!used[i])
            result.push_back(i);
    }

    return result;
}

template <typename Container>
static size_t binarySearchImpl(const Container &arr, int value, size_t end) {
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

size_t PmergeMe::binarySearchVector(const std::vector<int> &arr, int value, size_t end) const {
    return binarySearchImpl(arr, value, end);
}

size_t PmergeMe::binarySearchDeque(const std::deque<int> &arr, int value, size_t end) const {
    return binarySearchImpl(arr, value, end);
}

std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int> &data) {
    if (data.size() <= 1)
        return data;

    std::vector< std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;

    for (size_t i = 0; i + 1 < data.size(); i += 2) {
        int a = data[i];
        int b = data[i + 1];
        if (a > b)
            pairs.push_back(std::make_pair(b, a));
        else
            pairs.push_back(std::make_pair(a, b));
    }

    if (data.size() % 2 != 0) {
        hasStraggler = true;
        straggler = data[data.size() - 1];
    }

    std::vector<int> bigger;
    std::vector<int> smaller;

    for (size_t i = 0; i < pairs.size(); ++i) {
        smaller.push_back(pairs[i].first);
        bigger.push_back(pairs[i].second);
    }

    bigger = fordJohnsonVector(bigger);

    std::vector<int> result = bigger;

    if (!smaller.empty()) {
        size_t pos = binarySearchVector(result, smaller[0], result.size());
        result.insert(result.begin() + pos, smaller[0]);

        std::vector<size_t> order = buildJacobsthalOrder(smaller.size());
        for (size_t i = 0; i < order.size(); ++i) {
            size_t idx = order[i];
            if (idx == 0 || idx >= smaller.size())
                continue;
            size_t insertPos = binarySearchVector(result, smaller[idx], result.size());
            result.insert(result.begin() + insertPos, smaller[idx]);
        }
    }

    if (hasStraggler) {
        size_t pos = binarySearchVector(result, straggler, result.size());
        result.insert(result.begin() + pos, straggler);
    }

    return result;
}

std::deque<int> PmergeMe::fordJohnsonDeque(const std::deque<int> &data) {
    if (data.size() <= 1)
        return data;

    std::deque< std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;

    for (size_t i = 0; i + 1 < data.size(); i += 2) {
        int a = data[i];
        int b = data[i + 1];
        if (a > b)
            pairs.push_back(std::make_pair(b, a));
        else
            pairs.push_back(std::make_pair(a, b));
    }

    if (data.size() % 2 != 0) {
        hasStraggler = true;
        straggler = data[data.size() - 1];
    }

    std::deque<int> bigger;
    std::deque<int> smaller;

    for (size_t i = 0; i < pairs.size(); ++i) {
        smaller.push_back(pairs[i].first);
        bigger.push_back(pairs[i].second);
    }

    bigger = fordJohnsonDeque(bigger);

    std::deque<int> result = bigger;

    if (!smaller.empty()) {
        size_t pos = binarySearchDeque(result, smaller[0], result.size());
        result.insert(result.begin() + pos, smaller[0]);

        std::vector<size_t> order = buildJacobsthalOrder(smaller.size());
        for (size_t i = 0; i < order.size(); ++i) {
            size_t idx = order[i];
            if (idx == 0 || idx >= smaller.size())
                continue;
            size_t insertPos = binarySearchDeque(result, smaller[idx], result.size());
            result.insert(result.begin() + insertPos, smaller[idx]);
        }
    }

    if (hasStraggler) {
        size_t pos = binarySearchDeque(result, straggler, result.size());
        result.insert(result.begin() + pos, straggler);
    }

    return result;
}

void PmergeMe::sortVector(std::vector<int> &data) {
    data = fordJohnsonVector(data);
}

void PmergeMe::sortDeque(std::deque<int> &data) {
    data = fordJohnsonDeque(data);
}

void PmergeMe::run(int argc, char **argv) {
    parseArguments(argc, argv);
    printBefore();

    std::vector<int> vecCopy = _vectorData;
    std::deque<int> deqCopy = _dequeData;

    clock_t startVec = clock();
    sortVector(vecCopy);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    sortDeque(deqCopy);
    clock_t endDeq = clock();

    printAfter(vecCopy);

    double timeVec = static_cast<double>(endVec - startVec) * 1000000.0 / CLOCKS_PER_SEC;
    double timeDeq = static_cast<double>(endDeq - startDeq) * 1000000.0 / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << vecCopy.size()
              << " elements with std::vector : "
              << timeVec << " us" << "\n";

    std::cout << "Time to process a range of " << deqCopy.size()
              << " elements with std::deque : "
              << timeDeq << " us" << "\n";
}
