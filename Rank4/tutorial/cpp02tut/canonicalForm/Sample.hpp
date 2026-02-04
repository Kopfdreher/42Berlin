#ifndef SAMPLE_H
#define SAMPLE_H

#include <iostream>

class Sample {

public:
  Sample(); //Canonical
  Sample(int const n);
  Sample(Sample const & src); //Canonical
  ~Sample(); //Canonical

  Sample &operator=(Sample const &rhs); //Canonical

  int getFoo() const;

private:
  int _foo;

};

std::ostream &operator<<(std::ostream & o, Sample const & i);

#endif
