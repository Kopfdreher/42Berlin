#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <sys/time.h>
#include <vector>

typedef unsigned int uInt;

class PmergeMe {
public:
  PmergeMe();
  PmergeMe(PmergeMe const &src);
  PmergeMe &operator=(PmergeMe const &rhs);
  ~PmergeMe();

  void processInput(int argc, char **argv);
  static uInt comp_count;

private:
  std::vector<int> v;
  std::deque<int> d;

  bool parseInput(int argc, char **argv);
  double calculateTime(struct timeval &start, struct timeval &end);

  void sortVec(uInt block);
  void pairBlocks(uInt block, uInt numPairs);
  uInt binaryInsertBlock(std::vector<uInt> &mainChain, uInt start, uInt block,
                         uInt high);
  void buildChain(std::vector<uInt> &mainChain, uInt block, uInt numPairs,
                  bool hasOdd);
  void reconstructVec(std::vector<uInt> &mainChain, uInt block);
  void sortDeq(std::deque<int> &d);
};

#endif
