#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <string>
#include <sys/time.h>
#include <vector>

class PmergeMe {
public:
  PmergeMe();
  PmergeMe(PmergeMe const &src);
  PmergeMe &operator=(PmergeMe const &rhs);
  ~PmergeMe();

  void processInput(int argc, char **argv);
  static size_t getVecCompCount();
  static size_t getDeqCompCount();

private:
  struct ElementV {
    int value;
    std::vector<ElementV> sub_chain;
    static size_t comp_count;

    bool operator<(const ElementV &other) const {
      comp_count++;
      return value < other.value;
    }
  };

  struct ElementD {
    int value;
    std::deque<ElementD> sub_chain;
    static size_t comp_count;

    bool operator<(const ElementD &other) const {
      comp_count++;
      return value < other.value;
    }
  };

  std::vector<int> v;
  std::deque<int> d;

  bool parseInput(int argc, char **argv);
  double calculateTime(struct timeval &start, struct timeval &end);
  void upperBoundInsert(std::vector<ElementV> &main_chain, ElementV &value);

    // Vector Implementation
    void sortVecContainer(std::vector<ElementV> & arr);
    std::vector<size_t> generateJSeqVec(size_t n);

    // Deque Implementation
    void sortDeqContainer(std::deque<ElementD> & arr);
    std::deque<size_t> generateJSeqDeq(size_t n);
  };

#endif
