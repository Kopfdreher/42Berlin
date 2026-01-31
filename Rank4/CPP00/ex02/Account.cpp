#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

// public ----------------------------------------------------------------------

int Account::getNbAccounts(void) { return (_nbAccounts); }

int Account::getTotalAmount(void) { return (_totalAmount); }

int Account::getNbDeposits(void) { return (_totalNbDeposits); }

int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

void Account::displayAccountsInfos(void) {

  _displayTimestamp();
  std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
            << ";deposits:" << _totalNbDeposits
            << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit) {

  _accountIndex = _nbAccounts;
  _amount = initial_deposit;
  _totalAmount += initial_deposit;
  _nbDeposits = 0;
  _nbWithdrawals = 0;
  _nbAccounts++;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created"
            << std::endl;
}

Account::~Account(void) {
  _nbAccounts--;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"
            << std::endl;
}

void Account::makeDeposit(int deposit) {

  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
            << ";deposit:" << deposit << ";amount:" << _amount + deposit
            << ";nb_deposits:" << _nbDeposits + 1 << std::endl;
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {

  if (withdrawal > _amount) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
              << ";withdrawal:refused" << std::endl;
    return (0);
  } else {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
              << ";withdrawal:" << withdrawal
              << ";amount:" << _amount - withdrawal
              << ";nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    return (1);
  }
}

int Account::checkAmount(void) const { return (_amount); }

void Account::displayStatus(void) const {

  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
            << std::endl;
}

// private ---------------------------------------------------------------------

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {
  std::time_t timeInSec;
  std::tm *currentTime;
  char timeBuffer[30];

  timeInSec = std::time(NULL);
  currentTime = std::localtime(&timeInSec);
  std::strftime(timeBuffer, 30, "[%Y%m%d_%H%M%S] ", currentTime);
  std::cout << timeBuffer;
}

Account::Account(void) { _nbAccounts++; }
