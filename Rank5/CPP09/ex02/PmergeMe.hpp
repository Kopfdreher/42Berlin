#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>

class PmergeMe {

public:
  PmergeMe();
  PmergeMe(PmergeMe const &);
  PmergeMe &operator=(PmergeMe const &);
  ~PmergeMe();

  void processInput(int argc, char **argv);

private:
  std::vector<int> v;
  std::deque<int> d;

  // helper
  bool parseInput(int argc, char **argv);
  double calculateTime(struct timeval &start, struct timeval &end);

  // vector
  void sortVec();
  void sortPairsVec(std::vector<std::pair<int, int> > &pairs);
  std::vector<int> generateJSeqVec(int n);
  void insertPendVec(std::vector<int> &mainChain, std::vector<int> &pend);
  void insertLowerBoundVec(std::vector<int> &mainChain, int val);

  // deque
  void sortDeq();
  void sortPairsDeq(std::deque<std::pair<int, int> > &pairs);
  std::deque<int> generateJSeqDeq(int n);
  void insertPendDeq(std::deque<int> &mainChain, std::deque<int> &pend);
  void insertLowerBoundDeq(std::deque<int> &mainChain, int val);
};

#endif
