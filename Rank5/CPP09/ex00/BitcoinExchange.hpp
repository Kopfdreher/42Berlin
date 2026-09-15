#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {

public:
  BitcoinExchange();
  BitcoinExchange(BitcoinExchange const &);
  BitcoinExchange &operator=(BitcoinExchange const &);
  ~BitcoinExchange();

  void loadDatabase(std::string const &dbPath);
  void processInputFile(std::string const &inputPath);

private:
  std::map<std::string, float> _database;

  bool isValidDate(std::string const &date) const;
  bool isValidValue(std::string const &valStr, float &value) const;
  float getExchangeRate(std::string const &date) const;
  std::string trim(std::string const &str) const;
};

#endif
