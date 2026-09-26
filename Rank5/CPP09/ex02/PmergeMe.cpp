#include "PmergeMe.hpp"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>

uInt PmergeMe::comp_count = 0;

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

void PmergeMe::processInput(int argc, char **argv) {
  if (!parseInput(argc, argv)) {
    std::cerr << "Error" << std::endl;
    return;
  }

  std::cout << "Before: ";
  for (uInt i = 0; i < v.size(); ++i) {
    std::cout << v[i] << (i + 1 < v.size() ? " " : "");
  }
  std::cout << std::endl;

  // Vector processing

  struct timeval startVec, endVec;
  gettimeofday(&startVec, NULL);
  sortVec(1);
  gettimeofday(&endVec, NULL);

  std::cout << "After: ";
  for (uInt i = 0; i < v.size(); ++i) {
    std::cout << v[i] << (i + 1 < v.size() ? " " : "");
  }
  std::cout << std::endl;

  double timeVec = calculateTime(startVec, endVec);

  std::cout << "Time to process a range of " << v.size()
            << " elements with std::vector : " << timeVec << " us\n"
            << "Comparisons: " << comp_count << std::endl;

  // Deque processing
  /*
  struct timeval startDeq, endDeq;
  gettimeofday(&startDeq, NULL);
  sortDeqContainer(deqElements);
  gettimeofday(&endDeq, NULL);

  for (uInt i = 0; i < deqElements.size(); ++i) {
    d[i] = deqElements[i].value;
  }

  double timeDeq = calculateTime(startDeq, endDeq);

  std::cout << "Time to process a range of " << d.size()
            << " elements with std::deque : " << timeDeq << " us\n" <<
  "Comparisons: " << getDeqCompCount() << std::endl;
  */
}

// VECTOR

void PmergeMe::pairBlocks(uInt block, uInt numPairs) {
  for (uInt i = 0; i < numPairs; i += 2) {
    uInt leftLast = (i + 1) * block - 1;
    uInt rightLast = (i + 2) * block - 1;

    comp_count++;
    if (v[leftLast] > v[rightLast]) {
      std::swap_ranges(v.begin() + i * block, v.begin() + (i + 1) * block,
                       v.begin() + (i + 1) * block);
    }
  }
}

void PmergeMe::buildChain(std::vector<uInt> &mainChain, uInt block,
                          uInt numPairs, bool hasOdd) {
  // mainChain starts as [b1, a1]. pend[k] is b_{k+2}; pairPos[k] is the
  // current index of its pair a_{k+2} in mainChain.
  std::vector<uInt> pend;
  std::vector<uInt> pairPos;
  mainChain.push_back(0 * block); // b1
  mainChain.push_back(1 * block); // a1
  for (uInt i = 2; i < numPairs; i += 2) {
    pend.push_back(i * block); // b_k
    pairPos.push_back(static_cast<uInt>(mainChain.size()));
    mainChain.push_back((i + 1) * block); // a_k
  }
  // Step 4: Jacobsthal insertion. Jacob numbers count b1..b_n; b1 is already
  // on the main chain, so pend_idx = b - 2.
  static const uInt jNums[] = {1,  3,   5,   11,  21,   43,
                               85, 171, 341, 683, 1365, 2731};
  uInt last = 1;
  uInt nb = static_cast<uInt>(pend.size() + 1 + (hasOdd ? 1 : 0));
  for (uInt k = 1; k < sizeof(jNums) / sizeof(jNums[0]); ++k) {
    uInt curr = jNums[k];
    if (last >= nb)
      break;
    uInt upper = std::min(curr, nb);
    for (uInt b = upper; b > last; --b) {
      if (b < 2)
        continue;
      bool straggler = hasOdd && b == nb;
      uInt start = straggler ? numPairs * block : pend[b - 2];
      uInt limit =
          straggler ? static_cast<uInt>(mainChain.size()) : pairPos[b - 2];
      uInt inserted_at = binaryInsertBlock(mainChain, start, block, limit);
      for (uInt j = 0; j < pairPos.size(); ++j) {
        if (pairPos[j] >= inserted_at)
          ++pairPos[j];
      }
    }
    last = curr;
  }
}

void PmergeMe::sortVec(uInt block) {
  uInt numBlocks = v.size() / block;
  if (numBlocks < 2)
    return;
  bool hasOdd = numBlocks % 2;
  uInt numPairs = numBlocks - hasOdd;

  // Step 1: Pair up adjacent blocks
  pairBlocks(block, numPairs);

  // Step 2: Recursive step with doubled block size
  sortVec(block * 2);

  // Step 3: Build mainChain and pend using block start indices.
  std::vector<uInt> mainChain;
  buildChain(mainChain, block, numPairs, hasOdd);

  // Step 4: Reconstruct v for this level
  reconstructVec(mainChain, block);
}

void PmergeMe::reconstructVec(std::vector<uInt> &mainChain, uInt block) {
  uInt scratch[3200];
  uInt destIdx = 0;
  for (uInt i = 0; i < mainChain.size(); ++i) {
    uInt srcStart = mainChain[i];
    std::copy(v.begin() + srcStart, v.begin() + srcStart + block,
              scratch + destIdx);
    destIdx += block;
  }
  // Copy back into v
  std::copy(scratch, scratch + mainChain.size() * block, v.begin());
}

uInt PmergeMe::binaryInsertBlock(std::vector<uInt> &mainChain, uInt start,
                                 uInt block, uInt high) {
  int target_val = v[start + block - 1];
  uInt low = 0;

  while (low < high) {
    uInt mid = low + (high - low) / 2;
    comp_count++;

    uInt mid_start = mainChain[mid];
    int mid_val = v[mid_start + block - 1];

    if (mid_val < target_val) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  mainChain.insert(mainChain.begin() + low, start);
  return low;
}
