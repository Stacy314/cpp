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

void printVectorDebug(const std::vector<int>& v, const std::string& label) {
    std::cout << label;
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << "\n";
}

void printPairsDebug(const std::vector< std::pair<int, int> >& pairs, const std::string& label) {
    std::cout << label;
    for (size_t i = 0; i < pairs.size(); ++i)
        std::cout << "(" << pairs[i].first << "," << pairs[i].second << ") ";
    std::cout << "\n";
}

void printOrderDebug(const std::vector<size_t>& order, const std::string& label) {
    std::cout << label;
    for (size_t i = 0; i < order.size(); ++i)
        std::cout << order[i] << " ";
    std::cout << "\n";
}

std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int> &data) {
     if (data.size() == 1)
        return data;

     std::vector< std::pair<int, int> > pairs;
     int straggler = -1;

     for (size_t i = 0; i + 1 < data.size(); i += 2) {
         int a = data[i];
         int b = data[i + 1];
		
         if (a > b)
 		{
             pairs.push_back(std::make_pair(b, a));
 		}
         else
 		{
             pairs.push_back(std::make_pair(a, b));
 		}
     }

	// printPairsDebug(pairs, "Pairs after local sort: ");

     if (data.size() % 2 != 0) {
         straggler = data[data.size() - 1];
		 std::cout << "Straggler: " << straggler << "\n";
     }

     std::vector<int> bigger;
     std::vector<int> smaller;

     for (size_t i = 0; i < pairs.size(); ++i) {
         smaller.push_back(pairs[i].first);
         bigger.push_back(pairs[i].second);
     }

	 
	 printVectorDebug(smaller, "[Before] Smaller elements: ");
	 printVectorDebug(bigger, "[Before] Bigger elements ");

     std::cout << "\nRecursive call on bigger...\n";
     bigger = fordJohnsonVector(bigger);
	 printVectorDebug(smaller, "[After] Smaller elements: ");
     printVectorDebug(bigger, "[After] Bigger elements: ");

	 
     std::vector<int> result = bigger;
	 printVectorDebug(result, "Initial result = bigger: ");


     if (!smaller.empty()) {
        // std::cout << "Insert first smaller[0] = " << smaller[0] << "\n";
         size_t pos = binarySearch(result, smaller[0], result.size());
        // std::cout << "Position found by binarySearch: " << pos << "\n";
         result.insert(result.begin() + pos, smaller[0]);
        // printVectorDebug(result, "Result after inserting first smaller: ");

         std::vector<size_t> order = buildJacobsthalOrder(smaller.size());
		// printOrderDebug(order, "Jacobsthal insertion order: ");
         for (size_t i = 0; i < order.size(); ++i) {
             size_t idx = order[i];
             if (idx == 0 || idx >= smaller.size()){
                //std::cout << "Skip idx = " << idx << " (out of allowed range)\n";
                continue;
            }
            //std::cout << "Insert smaller[" << idx << "] = " << smaller[idx] << "\n";
            size_t insertPos = binarySearch(result, smaller[idx], result.size());
            //std::cout << "Position found by binarySearch: " << insertPos << "\n";
            result.insert(result.begin() + insertPos, smaller[idx]);
            //printVectorDebug(result, "Result after insertion: ");
        }
    } else {
        std::cout << "No smaller elements to insert\n";
    }

     if (straggler > -1) {
        std::cout << "Insert straggler = " << straggler << "\n";
        size_t pos = binarySearch(result, straggler, result.size());
        std::cout << "Position found by binarySearch: " << pos << "\n";
        result.insert(result.begin() + pos, straggler);
        printVectorDebug(result, "Result after straggler insertion: ");
     }

	     printVectorDebug(result, "Return from fordJohnsonVector(): ");
    std::cout << "==============================\n";
     return result;
 }

//std::deque<int> PmergeMe::fordJohnsonDeque(const std::deque<int> &data) {
//    if (data.size() <= 1)
//        return data;

//    std::deque< std::pair<int, int> > pairs;
//    int straggler = -1;
//    bool hasStraggler = false;

//    for (size_t i = 0; i + 1 < data.size(); i += 2) {
//        int a = data[i];
//        int b = data[i + 1];
//        if (a > b)
//            pairs.push_back(std::make_pair(b, a));
//        else
//            pairs.push_back(std::make_pair(a, b));
//    }

//    if (data.size() % 2 != 0) {
//        hasStraggler = true;
//        straggler = data[data.size() - 1];
//    }

//    std::deque<int> bigger;
//    std::deque<int> smaller;

//    for (size_t i = 0; i < pairs.size(); ++i) {
//        smaller.push_back(pairs[i].first);
//        bigger.push_back(pairs[i].second);
//    }

//    bigger = fordJohnsonDeque(bigger);

//    std::deque<int> result = bigger;

//    if (!smaller.empty()) {
//        size_t pos = binarySearch(result, smaller[0], result.size());
//        result.insert(result.begin() + pos, smaller[0]);

//        std::vector<size_t> order = buildJacobsthalOrder(smaller.size());
//        for (size_t i = 0; i < order.size(); ++i) {
//            size_t idx = order[i];
//            if (idx == 0 || idx >= smaller.size())
//                continue;
//            size_t insertPos = binarySearch(result, smaller[idx], result.size());
//            result.insert(result.begin() + insertPos, smaller[idx]);
//        }
//    }

//    if (hasStraggler) {
//        size_t pos = binarySearch(result, straggler, result.size());
//        result.insert(result.begin() + pos, straggler);
//    }

//    return result;
//}

void PmergeMe::run(int argc, char **argv) {
    parseArguments(argc, argv);
    printBefore();

    std::vector<int> vecCopy = _vectorData;
    //std::deque<int> deqCopy = _dequeData;

    clock_t startVec = clock();
    vecCopy = fordJohnsonVector(vecCopy);
    clock_t endVec = clock();

    //clock_t startDeq = clock();
    //deqCopy = fordJohnsonDeque(deqCopy);
    //clock_t endDeq = clock();

    printAfter(vecCopy);

    std::cout << std::fixed << std::setprecision(5);
    double timeVec = static_cast<double>(endVec - startVec);
    //double timeDeq = static_cast<double>(endDeq - startDeq);

    std::cout << "Time to process a range of " << vecCopy.size()
              << " elements with std::vector : "
              << timeVec << " us" << "\n";

    //std::cout << "Time to process a range of " << deqCopy.size()
    //          << " elements with std::deque : "
    //          << timeDeq << " us" << "\n";
}
