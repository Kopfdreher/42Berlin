#include "PmergeMe.hpp"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>

uShort PmergeMe::comp_count = 0;

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
  for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v[i] << (i + 1 < v.size() ? " " : "");
  }
  std::cout << std::endl;

  // Vector processing

  struct timeval startVec, endVec;
  gettimeofday(&startVec, NULL);
  sortVec(1);
  gettimeofday(&endVec, NULL);

  std::cout << "After: ";
  for (size_t i = 0; i < v.size(); ++i) {
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

  for (size_t i = 0; i < deqElements.size(); ++i) {
    d[i] = deqElements[i].value;
  }

  double timeDeq = calculateTime(startDeq, endDeq);

  std::cout << "Time to process a range of " << d.size()
            << " elements with std::deque : " << timeDeq << " us\n" <<
  "Comparisons: " << getDeqCompCount() << std::endl;
  */
}

// VECTOR

void PmergeMe::sortVec(uShort block) {
  uShort num_blocks = v.size() / block;
  if (num_blocks < 2)
    return;

  bool has_straggler = (num_blocks % 2 != 0);
  uShort paired_blocks = num_blocks - (has_straggler ? 1 : 0);

  // Step 1: Pair up adjacent blocks
  for (size_t i = 0; i < paired_blocks; i += 2) {
    uShort left_last = (i + 1) * block - 1;
    uShort right_last = (i + 2) * block - 1;

    comp_count++;
    if (v[left_last] > v[right_last]) {
      std::swap_ranges(v.begin() + i * block, v.begin() + (i + 1) * block,
                       v.begin() + (i + 1) * block);
    }
  }

  // Step 2: Recursive step with doubled block size
  sortVec(block * 2);

  // Step 3: Reconstruct main_chain and pend using block start indices.
  // main_chain starts as [b1, a1]. pend[k] is b_{k+2}; pair_pos[k] is the
  // current index of its pair a_{k+2} in main_chain.
  std::vector<uShort> main_chain;
  std::vector<uShort> pend;
  std::vector<uShort> pair_pos;

  main_chain.push_back(0 * block); // b1
  main_chain.push_back(1 * block); // a1

  for (size_t i = 2; i < paired_blocks; i += 2) {
    pend.push_back(i * block); // b_k
    pair_pos.push_back(static_cast<uShort>(main_chain.size()));
    main_chain.push_back((i + 1) * block); // a_k
  }

  // Step 4: Jacobsthal insertion. Jacob numbers count b1..b_n; b1 is already
  // on the main chain, so pend_idx = b - 2.
  static const uShort jacob_nums[] = {1,  3,   5,   11,  21,   43,
                                      85, 171, 341, 683, 1365, 2731};
  uShort last_jacob = 1;
  uShort nb = static_cast<uShort>(pend.size() + 1);

  for (size_t k = 1; k < sizeof(jacob_nums) / sizeof(jacob_nums[0]); ++k) {
    uShort curr_jacob = jacob_nums[k];
    if (last_jacob >= nb)
      break;

    uShort upper = std::min(curr_jacob, nb);

    for (uShort b = upper; b > last_jacob; --b) {
      if (b < 2)
        continue;

      uShort pend_idx = b - 2;
      uShort inserted_at =
          binaryInsertBlock(v, main_chain, pend[pend_idx], block,
                            pair_pos[pend_idx], comp_count);

      for (size_t j = 0; j < pair_pos.size(); ++j) {
        if (pair_pos[j] >= inserted_at)
          ++pair_pos[j];
      }
    }
    last_jacob = curr_jacob;
  }

  // Step 5: Straggler Insertion using the exact same helper
  if (has_straggler) {
    uShort straggler_start = paired_blocks * block;

    binaryInsertBlock(v, main_chain, straggler_start, block, main_chain.size(),
                      comp_count);
  }

  // Step 6: Reconstruct v for this level
  std::vector<int> cache;
  cache.reserve(num_blocks * block);

  for (size_t i = 0; i < main_chain.size(); ++i) {
    uShort src_start = main_chain[i];
    for (size_t j = 0; j < block; ++j) {
      cache.push_back(v[src_start + j]);
    }
  }

  for (size_t i = cache.size(); i < v.size(); ++i) {
    cache.push_back(v[i]);
  }

  std::copy(cache.begin(), cache.end(), v.begin());
}

uShort PmergeMe::binaryInsertBlock(std::vector<int> const &arr,
                                   std::vector<uShort> &main_chain,
                                   uShort block_start, uShort block_size,
                                   uShort search_limit, uShort &comp_count) {
  int target_val = arr[block_start + block_size - 1];

  uShort low = 0;
  uShort high = search_limit;

  while (low < high) {
    uShort mid = low + (high - low) / 2;
    comp_count++;

    uShort mid_block_start = main_chain[mid];
    int mid_val = arr[mid_block_start + block_size - 1];

    if (mid_val < target_val) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  main_chain.insert(main_chain.begin() + low, block_start);
  return low;
}
