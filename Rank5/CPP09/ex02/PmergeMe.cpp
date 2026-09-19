#include "PmergeMe.hpp"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <sys/time.h>

// public ----------------------------------------------------------------------

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &src) { *this = src; }

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {

  if (this != &rhs) {
    _vec = rhs.vec;
    _deq = rhs.deq;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::processInput(int argc, char **argv) {
  if (!parseInput(argc, argv)) {
    std::cerr << "Error" << std::endl;
    return;
  }

  std::cout << "Before: ";
  for (size_t i = 0; i < _vec.size(); ++i) {
    std::cout << _vec[i] << (i + 1 < _vec.size() ? " " : "");
  }
  std::cout << std::endl;

  struct timeval startVec, endVec;
  gettimeofday(&startVec, NULL);
  sortVec(_vec);
  gettimeofday(&endVec, NULL);
  double timeVec = calculateTime(startVec, endVec);

  struct timeval startDeq, endDeq;
  gettimeofday(&startDeq, NULL);
  sortDeq(_deq);
  gettimeofday(&endDeq, NULL);
  double timeDeq = calculateTime(startDeq, endDeq);

  std::cout << "After: ";
  for (size_t i = 0; i < _vec.size(); ++i) {
    std::cout << _vec[i] << (i + 1 < _vec.size() ? " " : "");
  }
  std::cout << std::endl;

  std::cout << "Time to process a range of " << _vec.size()
            << " elements with std::vector : " << timeVec << " us" << std::endl;
  std::cout << "Time to process a range of " << _deq.size()
            << " elements with std::deque : " << timeDeq << " us" << std::endl;
}

// private ---------------------------------------------------------------------

double PmergeMe::calculateTime(struct timeval &start, struct timeval &end) {
  return ((end.tv_sec - start.tv_sec) * 1000000.0 +
          (end.tv_usec - start.tv_usec));
}

bool PmergeMe::parseInput(int argc, char **argv) {
  for (int i = 1; i < argc; ++i) {
    std::string = arg = argv[i];
    if (arg.empty())
      return false;

    char *endPtr;
    long val = std::strtol(arg.c_str(), &endPtr, 10);

    if (*endPtr != '\0' || val < 0 || val > INT_MAX)
      return false;

    _vec.push_back(static_cast<int>(val));
    _deq.push_back(static_cast<int>(val));
  }
  return !_vec.empty();
}

// std::vector

std::vector<int> PmergeMe::generateJSeq(int n) {
  std::vector<int> jSeq;
  if (n <= 0)
    return jSeq;

  jSeq.push_back(1);
  if (n == 1)
    return jSeq;

  jSeq.push_back(3);
  while (true) {
    int next = jSeq.back() + 2 * jSeq[jSeq.size() - 2];
    if (next >= n)
      break;
    jSeq.push_back(next);
  }
  return jSeq;
}

void PmergeMe::sortVec(std::vector<int> &v) {
  if (v.size() <= 1)
    return;

  bool hasStraggler = (v.size() % 2 != 0);
  int straggler = 0;
  if (hasStraggler) {
    straggler = v.back();
    v.pop_back();
  }

  std::vector<int> mainChain;
  std::vector<int> pending;

  for (size_t i = 0; i < v.size(); i += 2) {
    if (v[i] > v[i + 1]) {
      mainChain.push_back(v[i]);
      pending.push_back(v[i + 1]);
    } else {
      mainChain.push_back(v[i + 1]);
      pending.push_back(v[i]);
    }
  }

  // sort main chain recursively
  sortVec(mainChain);

  if (!pending.empty()) {
    mainChain.insert(mainChain.begin(), pending[0]);
  }

  std::vector<int> jSeq = generateJSeqVec(pending.size());
  size_t lastIdx = 1;

  for (size_t i = 0; i < jSeq.size(); ++i) {
    size_t currIdx = jSeq[i];
    size_t end = std::min(currIdx, pending.size());

    for (size_t j = end; j > lastIdx; --j) {
      int val = pending[j - 1];
      std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val
    }
  }
}

// std::deque

std::deque<int> PmergeMe::generateJSeq(int n) {
  std::deque<int> jSeq;
  if (n <= 0)
    return jSeq;

  jSeq.push_back(1);
  if (n == 1)
    return jSeq;

  jSeq.push_back(3);
  while (true) {
    int next = jSeq.back() + 2 * jSeq[jSeq.size() - 2];
    if (next >= n)
      break;
    jSeq.push_back(next);
  }
  return jSeq;
}
