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

  double timeVec = calculateTime(startVec, endVec);

  std::cout << "After: ";
  for (uInt i = 0; i < v.size(); ++i) {
    std::cout << v[i] << (i + 1 < v.size() ? " " : "");
  }
  std::cout << std::endl;

  std::cout << "Time to process a range of " << v.size()
            << " elements with std::vector : " << timeVec << " us" << std::endl;

  // Deque processing

  struct timeval startDeq, endDeq;
  gettimeofday(&startDeq, NULL);
  sortDeq(1);
  gettimeofday(&endDeq, NULL);

  double timeDeq = calculateTime(startDeq, endDeq);

  std::cout << "Time to process a range of " << d.size()
            << " elements with std::deque : " << timeDeq << " us" << std::endl;

  COMPARISONS
}

// Fenwick Tree ----------------------------------------------------------------

uInt PmergeMe::lowbit(uInt i) const { return i & (~i + 1); }

void PmergeMe::addShift(uInt *bit, uInt bitSize, uInt pairIdx) const {
  for (uInt i = pairIdx + 1; i < bitSize; i += lowbit(i)) {
    bit[i] += 1;
  }
}

uInt PmergeMe::getPos(const uInt *bit, uInt pairIdx) const {
  uInt shift = 0;
  for (uInt i = pairIdx + 1; i > 0; i -= lowbit(i)) {
    shift += bit[i];
  }
  return pairIdx + 2 + shift;
}

uInt PmergeMe::findPairIndex(const uInt *bit, uInt high,
                             uInt insertedAt) const {
  uInt low = 0;
  while (low < high) {
    uInt mid = low + (high - low) / 2;
    if (getPos(bit, mid) < insertedAt) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return low;
}

// VECTOR ----------------------------------------------------------------------

void PmergeMe::sortVec(uInt block) {
  uInt numBlocks = v.size() / block;
  if (numBlocks < 2)
    return;
  bool hasOdd = numBlocks % 2;
  uInt numPairs = numBlocks - hasOdd;

  // Step 1: Pair up adjacent blocks
  pairBlocksVec(block, numPairs);

  // Step 2: Recursive step with doubled block size
  sortVec(block * 2);

  // Step 3: Build mainChain and pend using block indices
  std::vector<uInt> mainChain;
  buildChainVec(mainChain, block, numPairs, hasOdd);

  // Step 4: Reconstruct v for this level
  reconstructVec(mainChain, block);
}

void PmergeMe::pairBlocksVec(uInt block, uInt numPairs) {
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

void PmergeMe::buildChainVec(std::vector<uInt> &mainChain, uInt block,
                             uInt numPairs, bool hasOdd) {
  std::vector<uInt> pend;

  // Initialize mainChain with [b1, a1]
  mainChain.push_back(0 * block); // b1
  mainChain.push_back(1 * block); // a1
  // Populate pend with b_k and mainChain with a_k
  for (uInt i = 2; i < numPairs; i += 2) {
    pend.push_back(i * block);            // b_k
    mainChain.push_back((i + 1) * block); // a_k
  }

  uInt bit[1600] = {0};
  static const uInt jNums[] = {1,  3,   5,   11,  21,   43,
                               85, 171, 341, 683, 1365, 2731};
  uInt last = 1;
  uInt totalBCount = static_cast<uInt>(pend.size() + 1 + hasOdd);

  for (size_t k = 1; k < sizeof(jNums) / sizeof(jNums[0]); ++k) {
    uInt curr = jNums[k];
    if (last >= totalBCount)
      break;

    uInt upper = std::min(curr, totalBCount);
    for (uInt b = upper; b > last; --b) {
      if (b < 2)
        continue;
      uInt start;
      uInt limit;
      if (hasOdd && b == totalBCount) {
        start = numPairs * block;
        limit = mainChain.size();
      } else {
        start = pend[b - 2];
        limit = getPos(bit, b - 2);
      }

      // Perform bounded binary insertion
      uInt insertedAt = binaryInsertVec(mainChain, start, block, limit);

      // Map inserted position back to a pair index and update insertion offsets
      uInt pairIdx = findPairIndex(bit, numPairs, insertedAt);
      if (pairIdx < numPairs)
        addShift(bit, numPairs, pairIdx);
    }
    last = curr;
  }
}

void PmergeMe::reconstructVec(std::vector<uInt> &mainChain, uInt block) {
  uInt cache[3200];
  uInt destIdx = 0;
  for (uInt i = 0; i < mainChain.size(); ++i) {
    uInt srcStart = mainChain[i];
    std::copy(v.begin() + srcStart, v.begin() + srcStart + block,
              cache + destIdx);
    destIdx += block;
  }
  // Copy back into v
  std::copy(cache, cache + mainChain.size() * block, v.begin());
}

uInt PmergeMe::binaryInsertVec(std::vector<uInt> &mainChain, uInt start,
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

// DEQUE -----------------------------------------------------------------------

void PmergeMe::sortDeq(uInt block) {
  uInt numBlocks = v.size() / block;
  if (numBlocks < 2)
    return;
  bool hasOdd = numBlocks % 2;
  uInt numPairs = numBlocks - hasOdd;

  // Step 1: Pair up adjacent blocks
  pairBlocksDeq(block, numPairs);

  // Step 2: Recursive step with doubled block size
  sortDeq(block * 2);

  // Step 3: Build mainChain and pend using block indices
  std::deque<uInt> mainChain;
  buildChainDeq(mainChain, block, numPairs, hasOdd);

  // Step 4: Reconstruct v for this level
  reconstructDeq(mainChain, block);
}

void PmergeMe::pairBlocksDeq(uInt block, uInt numPairs) {
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

void PmergeMe::buildChainDeq(std::deque<uInt> &mainChain, uInt block,
                             uInt numPairs, bool hasOdd) {
  std::deque<uInt> pend;

  // Initialize mainChain with [b1, a1]
  mainChain.push_back(0 * block); // b1
  mainChain.push_back(1 * block); // a1
  // Populate pend with b_k and mainChain with a_k
  for (uInt i = 2; i < numPairs; i += 2) {
    pend.push_back(i * block);            // b_k
    mainChain.push_back((i + 1) * block); // a_k
  }

  uInt bit[1600] = {0};
  static const uInt jNums[] = {1,  3,   5,   11,  21,   43,
                               85, 171, 341, 683, 1365, 2731};
  uInt last = 1;
  uInt totalBCount = static_cast<uInt>(pend.size() + 1 + hasOdd);

  for (size_t k = 1; k < sizeof(jNums) / sizeof(jNums[0]); ++k) {
    uInt curr = jNums[k];
    if (last >= totalBCount)
      break;

    uInt upper = std::min(curr, totalBCount);
    for (uInt b = upper; b > last; --b) {
      if (b < 2)
        continue;
      uInt start;
      uInt limit;
      if (hasOdd && b == totalBCount) {
        start = numPairs * block;
        limit = mainChain.size();
      } else {
        start = pend[b - 2];
        limit = getPos(bit, b - 2);
      }

      // Perform bounded binary insertion
      uInt insertedAt = binaryInsertDeq(mainChain, start, block, limit);

      // Map inserted position back to a pair index and update insertion offsets
      uInt pairIdx = findPairIndex(bit, numPairs, insertedAt);
      if (pairIdx < numPairs)
        addShift(bit, numPairs, pairIdx);
    }
    last = curr;
  }
}

void PmergeMe::reconstructDeq(std::deque<uInt> &mainChain, uInt block) {
  uInt cache[3200];
  uInt destIdx = 0;
  for (uInt i = 0; i < mainChain.size(); ++i) {
    uInt srcStart = mainChain[i];
    std::copy(v.begin() + srcStart, v.begin() + srcStart + block,
              cache + destIdx);
    destIdx += block;
  }
  // Copy back into v
  std::copy(cache, cache + mainChain.size() * block, v.begin());
}

uInt PmergeMe::binaryInsertDeq(std::deque<uInt> &mainChain, uInt start,
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
