#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &dbFile) {
    loadDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        _db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string &s) {
    std::string::size_type start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
        ++start;

    std::string::size_type end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
        --end;

    return s.substr(start, end - start);
}

bool BitcoinExchange::isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string &date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;

    int daysInMonth[12] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}

bool BitcoinExchange::parseValue(const std::string &s, double &value) {
    char *end = NULL;
    value = std::strtod(s.c_str(), &end);
    if (s.empty() || *end != '\0')
        return false;
    return true;
}

void BitcoinExchange::loadDatabase(const std::string &dbFile) {
    std::ifstream file(dbFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");

    std::string line;
    if (!std::getline(file, line))
        throw std::runtime_error("Error: empty database.");

    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::string::size_type comma = line.find(',');
        if (comma == std::string::npos)
            continue;

        std::string date = trim(line.substr(0, comma));
        std::string rateStr = trim(line.substr(comma + 1));

        if (!isValidDate(date))
            continue;

        double rate;
        if (!parseValue(rateStr, rate))
            continue;

        _db[date] = rate;
    }

    if (_db.empty())
        throw std::runtime_error("Error: database has no valid entries.");
}

double BitcoinExchange::getRateForDate(const std::string &date) const {
    std::map<std::string, double>::const_iterator it = _db.lower_bound(date);

    if (it != _db.end() && it->first == date)
        return it->second;

    if (it == _db.begin())
        throw std::runtime_error("Error: no earlier date in database.");

    --it;
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string &inputFile) const {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cout << "Error: could not open file." << "\n";
        return;
    }
    std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty file.");

	if (line != "date | value"){

		throw std::runtime_error("Error: bad header.");
	}

    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::string::size_type separator = line.find('|');
        if (separator == std::string::npos) {
            std::cout << "Error: bad input => " << line << "\n";
            continue;
        }

        std::string date = trim(line.substr(0, separator));
        std::string valueStr = trim(line.substr(separator + 1));

        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << line << "\n";
            continue;
        }

        double value;
        if (!parseValue(valueStr, value)) {
            std::cout << "Error: bad input => " << line << "\n";
            continue;
        }

        if (value < 0) {
            std::cout << "Error: not a positive number." << "\n";
            continue;
        }

        if (value > 1000) {
            std::cout << "Error: too large a number." << "\n";
            continue;
        }

        try {
            double rate = getRateForDate(date);
            std::cout << date << " => " << value << " = " << (value * rate) << "\n";
        } catch (const std::exception &) {
            std::cout << "Error: bad input => " << line << "\n";
        }


    }
}
