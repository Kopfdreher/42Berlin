#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

// public ----------------------------------------------------------------------

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
  if (this != &rhs)
    _database = rhs._database;
  return *this;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) { *this = src; }

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(std::string const &dbPath) {
  std::ifstream file(dbPath.c_str());
  if (!file.is_open()) {
    throw std::runtime_error("Error: could not open database file.");
  }

  std::string line;
  std::getline(file, line); // skip header

  while (std::getline(file, line)) {
    std::size_t commaPos = line.find(',');
    if (commaPos == std::string::npos)
      continue;

    std::string date = trim(line.substr(0, commaPos));
    float rate =
        static_cast<float>(std::atof(line.substr(commaPos + 1).c_str()));
    _database[date] = rate;
  }
  file.close();
}

void BitcoinExchange::processInputFile(std::string const &inputPath) {
  std::ifstream file(inputPath.c_str());
  if (!file.is_open()) {
    std::cerr << "Error: could not open file." << std::endl;
    return;
  }

  std::string line;
  std::getline(file, line); // skip header

  while (std::getline(file, line)) {
    std::size_t pipePos = line.find('|');
    if (pipePos == std::string::npos) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }

    std::string date = trim(line.substr(0, pipePos));
    std::string valStr = trim(line.substr(pipePos + 1));

    if (!isValidDate(date)) {
      std::cerr << "Error: bad input => " << date << std::endl;
      continue;
    }

    float value;
    if (!isValidValue(valStr, value))
      continue;

    float rate = getExchangeRate(date);
    std::cout << date << " => " << value << " = " << (value * rate)
              << std::endl;
  }
  file.close();
}

// private ---------------------------------------------------------------------

// std::map<std::string, float> _database;

bool BitcoinExchange::isValidDate(std::string const &date) const {
  if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;

  for (int i = 0; i < 10; ++i) {
    if (i == 4 || i == 7) continue;
    if (!std::isdigit(date[i])) return false;
  }

  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());

  if (month < 1 || month > 12 || day < 1 || day > 31) return false;

  int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
  if (month == 2 && isLeap) daysInMonth[2] = 29;
  if (day > daysInMonth[month]) return false;

  return true;
}

bool BitcoinExchange::isValidValue(std::string const &valStr,
                                   float &value) const {
  if (valStr.empty()) {
    std::cerr << "Error: bad input => empty value" << std::endl;
    return false;
  }

  char *endPtr;
  double val = std::strtod(valStr.c_str(), &endPtr);

  if (*endPtr != '\0') {
    std::cerr << "Error: bad input => " << valStr << std::endl;
    return false;
  }

  if (val < 0) {
    std::cerr << "Error: not a positive number." << std::endl;
    return false;
  }

  if (val > 1000) {
    std::cerr << "Error: too large number." << std::endl;
    return false;
  }

  value = static_cast<float>(val);
  return true;
}

float BitcoinExchange::getExchangeRate(std::string const &date) const {
  if (_database.empty()) return 0.0f;

  std::map<std::string, float>::const_iterator it = _database.find(date);
  if (it != _database.end())
    return it->second;

  it = _database.lower_bound(date);
  if (it == _database.begin())
    return 0.0f;
  --it;
  return it->second;
}

std::string BitcoinExchange::trim(std::string const &str) const {
  std::size_t first = str.find_first_not_of(" \t\r\n");
  if (first == std::string::npos)
    return "";
  std::size_t last = str.find_last_not_of(" \t\r\n");
  return str.substr(first, last - first + 1);
}
