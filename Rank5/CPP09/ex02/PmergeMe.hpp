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

  void sortVec();
  std::vector<int> generateJSeqVec(int n);

  void sortDeq();
  std::deque<int> generateJSeqDeq(int n);

  bool parseInput(int argc, char **argv);
  double calculateTime(struct timeval &start, struct timeval &end);
};

#endif
