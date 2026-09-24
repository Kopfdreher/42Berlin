#include "PmergeMe.hpp"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>

size_t PmergeMe::ElementV::comp_count = 0;
size_t PmergeMe::ElementD::comp_count = 0;

size_t PmergeMe::getVecCompCount() { return ElementV::comp_count; }

size_t PmergeMe::getDeqCompCount() { return ElementD::comp_count; }

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
  std::vector<ElementV> vecElements;
  vecElements.reserve(v.size());
  for (size_t i = 0; i < v.size(); ++i) {
    ElementV el;
    el.value = v[i];
    vecElements.push_back(el);
  }

  struct timeval startVec, endVec;
  gettimeofday(&startVec, NULL);
  sortVecContainer(vecElements);
  gettimeofday(&endVec, NULL);

  for (size_t i = 0; i < vecElements.size(); ++i) {
    v[i] = vecElements[i].value;
  }

  std::cout << "After: ";
  for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v[i] << (i + 1 < v.size() ? " " : "");
  }
  std::cout << std::endl;

  double timeVec = calculateTime(startVec, endVec);

  std::cout << "Time to process a range of " << v.size()
            << " elements with std::vector : " << timeVec << " us\n"
            << "Comparisons: " << getVecCompCount() << std::endl;

  // Deque processing
  /*
  std::deque<ElementD> deqElements;
  for (size_t i = 0; i < d.size(); ++i) {
    ElementD el;
    el.value = d[i];
    deqElements.push_back(el);
  }

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

std::vector<size_t> PmergeMe::generateJSeqVec(size_t n) {
  std::vector<size_t> seq;
  if (n == 0)
    return seq;

  size_t last = 1;
  size_t curr = 3;

  while (last < n) {
    size_t upper = std::min(curr, n);
    for (size_t i = upper; i > last; --i) {
      seq.push_back(i - 1); // 0-based indexing
    }
    size_t next = curr + 2 * last;
    last = curr;
    curr = next;
  }
  return seq;
}

void PmergeMe::sortVecContainer(std::vector<ElementV> &arr) {
  if (arr.size() <= 1)
    return;

  bool has_straggler = (arr.size() % 2 != 0);
  ElementV straggler;
  if (has_straggler) {
    straggler = arr.back();
    arr.pop_back();
  }

  // Step 1: Pair up adjacent elements, attach smaller to larger's sub_chain
  std::vector<ElementV> pairs;
  pairs.reserve(arr.size() / 2);

  for (size_t i = 0; i < arr.size(); i += 2) {
    if (arr[i].value < arr[i + 1].value) {
      arr[i + 1].sub_chain.push_back(arr[i]);
      pairs.push_back(arr[i + 1]);
    } else {
      arr[i].sub_chain.push_back(arr[i + 1]);
      pairs.push_back(arr[i]);
    }
  }

  // Step 2: Recursively sort main chain pairs
  sortVecContainer(pairs);

  // Step 3: Reconstruct Main Chain and Pend
  std::vector<ElementV> main_chain;
  std::vector<ElementV> pend;
  main_chain.reserve(arr.size() + 1);// (has_straggler ? 1 : 0));
  pend.reserve(pairs.size());

  for (size_t i = 0; i < pairs.size(); ++i) {
    ElementV pend_elem = pairs[i].sub_chain.back();
    pairs[i].sub_chain.pop_back();

    main_chain.push_back(pairs[i]);
    pend.push_back(pend_elem);
  }

  // b_1 (pend[0]) is guaranteed <= a_1 (main_chain[0]), insert at index 0
  main_chain.insert(main_chain.begin(), pend[0]);

  // Step 4: Jacobsthal Group Insertions
  std::vector<size_t> jacob_order = generateJSeqVec(pend.size());

  for (size_t i = 0; i < jacob_order.size(); ++i) {
    size_t pend_idx = jacob_order[i];
    if (pend_idx == 0)
      continue; // pend[0] already inserted
    ElementV item = pend[pend_idx];

    std::vector<ElementV>::iterator bound_it = main_chain.end();
    for (std::vector<ElementV>::iterator it = main_chain.begin(); it != main_chain.end(); ++it) {
	    if (it->value == pairs[pend_idx].value) {
		    bound_it = it;
		    break;
	    }
    }

    std::vector<ElementV>::iterator pos =
        std::upper_bound(main_chain.begin(), bound_it, item);

    main_chain.insert(pos, item);
  }

  // Step 5: Insert straggler if odd length
  if (has_straggler) {
    std::vector<ElementV>::iterator pos =
        std::upper_bound(main_chain.begin(), main_chain.end(), straggler);
    main_chain.insert(pos, straggler);
  }

  arr = main_chain;
}

// DEQUE
/*
std::deque<size_t> PmergeMe::generateJSeqDeq(size_t n) {
  std::deque<size_t> seq;
  if (n == 0)
    return seq;

  size_t last = 1;
  size_t curr = 3;

  while (last < n) {
    size_t upper = std::min(curr, n);
    for (size_t i = upper; i > last; --i) {
      seq.push_back(i - 1);
    }
    size_t temp = curr;
    curr = curr + 2 * last;
    last = temp;
  }
  return seq;
}

void PmergeMe::sortDeqContainer(std::deque<ElementD> &arr) {
  if (arr.size() <= 1)
    return;

  bool has_straggler = (arr.size() % 2 != 0);
  ElementD straggler;
  if (has_straggler) {
    straggler = arr.back();
    arr.pop_back();
  }

  std::deque<ElementD> pairs;
  for (size_t i = 0; i < arr.size(); i += 2) {
    if (arr[i].value < arr[i + 1].value) {
      arr[i + 1].sub_chain.push_back(arr[i]);
      pairs.push_back(arr[i + 1]);
    } else {
      arr[i].sub_chain.push_back(arr[i + 1]);
      pairs.push_back(arr[i]);
    }
  }

  sortDeqContainer(pairs);

  std::deque<ElementD> main_chain;
  std::deque<ElementD> pend;

  for (size_t i = 0; i < pairs.size(); ++i) {
    ElementD pend_elem = pairs[i].sub_chain.back();
    pairs[i].sub_chain.pop_back();

    main_chain.push_back(pairs[i]);
    pend.push_back(pend_elem);
  }

  main_chain.push_front(pend[0]);

  std::deque<size_t> jacob_order = generateJSeqDeq(pend.size());

  for (size_t i = 0; i < jacob_order.size(); ++i) {
    size_t pend_idx = jacob_order[i];
    if (pend_idx == 0)
      continue;

    ElementD item = pend[pend_idx];

    size_t search_bound =
        std::min(pend_idx + main_chain.size(), main_chain.size());

    std::deque<ElementD>::iterator bound_it = main_chain.begin() + search_bound;
    std::deque<ElementD>::iterator pos =
        std::upper_bound(main_chain.begin(), bound_it, item);

    main_chain.insert(pos, item);
  }

  if (has_straggler) {
    std::deque<ElementD>::iterator pos =
        std::upper_bound(main_chain.begin(), main_chain.end(), straggler);
    main_chain.insert(pos, straggler);
  }

  arr = main_chain;
}
*/
