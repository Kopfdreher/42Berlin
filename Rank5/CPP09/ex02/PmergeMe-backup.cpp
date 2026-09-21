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
    v = rhs.v;
    d = rhs.d;
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
  for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v[i] << (i + 1 < v.size() ? " " : "");
  }
  std::cout << std::endl;

  struct timeval startVec, endVec;
  gettimeofday(&startVec, NULL);
  sortVec();
  gettimeofday(&endVec, NULL);
  double timeVec = calculateTime(startVec, endVec);

  struct timeval startDeq, endDeq;
  gettimeofday(&startDeq, NULL);
  sortDeq();
  gettimeofday(&endDeq, NULL);
  double timeDeq = calculateTime(startDeq, endDeq);

  std::cout << "After: ";
  for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v[i] << (i + 1 < v.size() ? " " : "");
  }
  std::cout << std::endl;

  std::cout << "Time to process a range of " << v.size()
            << " elements with std::vector : " << timeVec << " us" << std::endl;
  std::cout << "Time to process a range of " << d.size()
            << " elements with std::deque : " << timeDeq << " us" << std::endl;
}

// private ---------------------------------------------------------------------

double PmergeMe::calculateTime(struct timeval &start, struct timeval &end) {
  return ((end.tv_sec - start.tv_sec) * 1000000.0 +
          (end.tv_usec - start.tv_usec));
}

bool PmergeMe::parseInput(int argc, char **argv) {
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (arg.empty())
      return false;

    char *endPtr;
    long val = std::strtol(arg.c_str(), &endPtr, 10);

    if (*endPtr != '\0' || val < 0 || val > INT_MAX)
      return false;

    v.push_back(static_cast<int>(val));
    d.push_back(static_cast<int>(val));
  }
  return !v.empty();
}

// std::vector

std::vector<int> PmergeMe::generateJSeqVec(int n) {
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

void PmergeMe::sortVec() {
  if (v.size() <= 1)
    return;

  bool hasStraggler = (v.size() % 2 != 0);
  int straggler = 0;
  if (hasStraggler) {
    straggler = v.back();
    v.pop_back();
  }

  // Setup initial
  std::vector<std::pair<int, int> > pairs;
  for (size_t i = 0; i < v.size(); i += 2) {
    if (v[i] > v[i + 1])
      pairs.push_back(std::make_pair(v[i], v[i + 1]));
    else
      pairs.push_back(std::make_pair(v[i + 1], v[i]));
  }

  // recursive sort
  sortPairsVec(pairs);

  // into mainChain and pend
  std::vector<int> mainChain;
  std::vector<int> pend;
  for (size_t i = 0; i < pairs.size(); i++) {
    mainChain.push_back(pairs[i].first);
    pend.push_back(pairs[i].second);
  }

  insertPendVec(mainChain, pend);

  if (hasStraggler)
    insertLowerBoundVec(mainChain, straggler);

  v = mainChain;
}

void PmergeMe::sortPairsVec(std::vector<std::pair<int, int> > &pairs) {
  if (pairs.size() <= 1)
    return;

  bool hasStraggler = (pairs.size() % 2 != 0);
  std::pair<int, int> straggler;
  if (hasStraggler) {
    straggler = pairs.back();
    pairs.pop_back();
  }

  std::vector<std::pair<int, int> > higherPairs;
  std::vector<std::pair<int, int> > higherPairs;
  for (size_t i = 0; i < pairs.size(); i += 2) {
    if (pairs[i].first > pairs[i + 1].first)
      higherPairs.push_back(pairs[i]);
    else
      higherPairs.push_back(pairs[i + 1]);
  }

  // recursive Call
  sortPairsVec(higherPairs);

  std::vector<std::pair<int, int> > sortedPairs;
  for (size_t i = 0; i < higherPairs.size(); i++)
    sortedPairs.push_back(higherPairs[i]);
  if (hasStraggler)
    sortedPairs.push_back(straggler);
  pairs = sortedPairs;
}

void PmergeMe::insertPendVec(std::vector<int> &mainChain,
                             std::vector<int> &pend) {
  if (pend.empty())
    return;

  mainChain.insert(mainChain.begin(), pend[0]);

  std::vector<int> jSeq = generateJSeqVec(pend.size());
  size_t lastIdx = 1;

  for (size_t i = 0; i < jSeq.size(); ++i) {
    size_t currIdx = jSeq[i];
    size_t end = std::min(currIdx, pend.size());
    for (size_t j = end; j > lastIdx; --j)
      insertLowerBoundVec(mainChain, pend[j - 1]);
    lastIdx = currIdx;
  }

  for (size_t j = pend.size(); j > lastIdx; --j)
    insertLowerBoundVec(mainChain, pend[j - 1]);
}

void PmergeMe::insertLowerBoundVec(std::vector<int> &mainChain, int val) {
  std::vector<int>::iterator pos =
      std::lower_bound(mainChain.begin(), mainChain.end(), val);
  mainChain.insert(pos, val);
}

// std::deque

void PmergeMe::sortDeq() {
  if (d.empty())
    return;
}
void PmergeMe::sortPairsDeq(std::deque<std::pair<int, int> > &pairs) {
  if (pairs.size() <= 1)
    return;
}

std::deque<int> PmergeMe::generateJSeqDeq(int n) {
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

void PmergeMe::insertPendDeq(std::deque<int> &mainChain, std::deque<int> &pend) {
  if (mainChain.empty() || pend.empty()) return;
}
void PmergeMe::insertLowerBoundDeq(std::deque<int> &mainChain, int val) {
  std::deque<int>::iterator pos =
      std::lower_bound(mainChain.begin(), mainChain.end(), val);
  mainChain.insert(pos, val);
}
