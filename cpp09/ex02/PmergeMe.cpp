#include "PmergeMe.hpp"


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

        for (size_t j = 0; j < _vectorData.size(); ++j) {
            if (_vectorData[j] == static_cast<int>(value))
                throw std::runtime_error("Error");
        }

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

std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int> &data) {
    if (data.size() == 1)
		return data;

    std::vector< std::pair<int, int> > pairs;
    int odd = -1;

    for (size_t i = 0; i + 1 < data.size(); i += 2) {
        int a = data[i];
        int b = data[i + 1];
		if (a > b)
            pairs.push_back(std::make_pair(b, a));
        else
            pairs.push_back(std::make_pair(a, b));
    }

    if (data.size() % 2 != 0)
        odd = data[data.size() - 1];

    std::vector<int> mainChain;
    std::vector<int> pend;

    for (size_t i = 0; i < pairs.size(); ++i) {
        pend.push_back(pairs[i].first);
        mainChain.push_back(pairs[i].second);
    }

    mainChain = fordJohnsonVector(mainChain);

    if (!pend.empty()) {
        size_t pos = binarySearch(mainChain, pend[0], mainChain.size());
        mainChain.insert(mainChain.begin() + pos, pend[0]);

        std::vector<size_t> order = buildJacobsthalOrder(pend.size());
		insertPendElements(mainChain, pend, order);
    }

    if (odd > -1) {
        size_t pos = binarySearch(mainChain, odd, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, odd);
    }

    return mainChain;
}


std::deque<int> PmergeMe::fordJohnsonDeque(const std::deque<int> &data) {
    if (data.size() <= 1)
        return data;

    std::deque< std::pair<int, int> > pairs;
    int odd = -1;

    for (size_t i = 0; i + 1 < data.size(); i += 2) {
        int a = data[i];
        int b = data[i + 1];
        if (a > b)
            pairs.push_back(std::make_pair(b, a));
        else
            pairs.push_back(std::make_pair(a, b));
    }

    if (data.size() % 2 != 0) {
        odd = data[data.size() - 1];
    }

    std::deque<int> mainChain;
    std::deque<int> pend;

    for (size_t i = 0; i < pairs.size(); ++i) {
        pend.push_back(pairs[i].first);
        mainChain.push_back(pairs[i].second);
    }

    mainChain = fordJohnsonDeque(mainChain);

    if (!pend.empty()) {
        size_t pos = binarySearch(mainChain, pend[0], mainChain.size());
        mainChain.insert(mainChain.begin() + pos, pend[0]);

        std::vector<size_t> order = buildJacobsthalOrder(pend.size());
		insertPendElements(mainChain, pend, order);
    }

    if (odd > -1) {
        size_t pos = binarySearch(mainChain, odd, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, odd);
    }

    return mainChain;
}

void PmergeMe::run(int argc, char **argv) {
    parseArguments(argc, argv);
    printBefore();

    std::vector<int> vecCopy = _vectorData;
    std::deque<int> deqCopy = _dequeData;

    clock_t startVec = clock();
    vecCopy = fordJohnsonVector(vecCopy);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    deqCopy = fordJohnsonDeque(deqCopy);
    clock_t endDeq = clock();

    printAfter(vecCopy);
	printAfter(deqCopy);
	
    std::cout << std::fixed << std::setprecision(5);
    double timeVec = static_cast<double>(endVec - startVec);
    double timeDeq = static_cast<double>(endDeq - startDeq);

    std::cout << "Time to process a range of " << vecCopy.size()
              << " elements with std::vector : "
              << timeVec << " us" << "\n";

    std::cout << "Time to process a range of " << deqCopy.size()
              << " elements with std::deque : "
              << timeDeq << " us" << "\n";
}
