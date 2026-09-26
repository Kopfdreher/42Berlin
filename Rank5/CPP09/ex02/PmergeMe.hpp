#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <sys/time.h>
#include <vector>

#ifndef COMPARE
#define COMPARE false
#endif

#define COMPARISONS                                                            \
  if (!COMPARE) {                                                              \
  } else                                                                       \
    std::cout << "Comparisons: " << comp_count << std::endl;

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

  // FenwickTree
  uInt lowbit(uInt i) const;
  void addShift(uInt *bit, uInt bitSize, uInt pairIdx) const;
  uInt getPos(const uInt *bit, uInt pairIdx) const;
  uInt findPairIndex(const uInt *bit, uInt totalPairs, uInt insertedAt) const;

  // Vector
  void sortVec(uInt block);
  void pairBlocksVec(uInt block, uInt numPairs);
  uInt binaryInsertVec(std::vector<uInt> &mainChain, uInt start, uInt block,
                       uInt high);
  void buildChainVec(std::vector<uInt> &mainChain, uInt block, uInt numPairs,
                     bool hasOdd);
  void reconstructVec(std::vector<uInt> &mainChain, uInt block);

  // Deque
  void sortDeq(uInt block);
  void pairBlocksDeq(uInt block, uInt numPairs);
  uInt binaryInsertDeq(std::deque<uInt> &mainChain, uInt start, uInt block,
                       uInt high);
  void buildChainDeq(std::deque<uInt> &mainChain, uInt block, uInt numPairs,
                     bool hasOdd);
  void reconstructDeq(std::deque<uInt> &mainChain, uInt block);
};

#endif
