#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <cctype>
#include <iostream>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const std::string &dbFile);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void processInputFile(const std::string &inputFile) const;

private:
    std::map<std::string, double> _db;
    void loadDatabase(const std::string &dbFile);
    static std::string trim(const std::string &s);
    static bool isLeapYear(int year);
    static bool isValidDate(const std::string &date);
    static bool parseValue(const std::string &s, double &value);
    double getRateForDate(const std::string &date) const;
};

#endif
