#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

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
    static std::string trim(const std::string &s);
    static bool isLeapYear(int year);
    static bool isValidDate(const std::string &date);
    static bool parseValue(const std::string &s, double &value);
    double getRateForDate(const std::string &date) const;
	void loadDatabase(const std::string &dbFile);
};

#endif
