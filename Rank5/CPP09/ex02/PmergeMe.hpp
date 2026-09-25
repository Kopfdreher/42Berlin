#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <sys/time.h>
#include <vector>

typedef unsigned short uShort;

class PmergeMe {
public:
  PmergeMe();
  PmergeMe(PmergeMe const &src);
  PmergeMe &operator=(PmergeMe const &rhs);
  ~PmergeMe();

  void processInput(int argc, char **argv);
  static uShort comp_count;

private:
  std::vector<int> v;
  std::deque<int> d;

  bool parseInput(int argc, char **argv);
  double calculateTime(struct timeval &start, struct timeval &end);

  void sortVec(uShort block);
  uShort binaryInsertBlock(std::vector<uShort> &mainChain, uShort start,
                           uShort block, uShort high);
  void sortDeq(std::deque<int> &d);
};

#endif
