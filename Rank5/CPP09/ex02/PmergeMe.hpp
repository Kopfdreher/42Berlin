#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {

public:
  PmergeMe();
  PmergeMe(PmergeMe const &);
  PmergeMe &operator=(PmergeMe const &);
  ~PmergeMe();

  void processInput(int argc, char **argv);

private:
  std::vector<int> _vec;
  std::deque<int> _deq;

  void sortVec(std::vector<int> &v);
  void sortDeq(std::deque<int> &d);

  std::vector<int> generateJSeq(int n);
  bool parseInput(int argc, char **argv);
};

#endif
