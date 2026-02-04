#ifndef SAMPLE_H
#define SAMPLE_H

#include <iostream>

class Sample {

public:
  Sample(); //Canonical Constructor
  Sample(int const n);
  Sample(Sample const & src); //Canonical Copy Constructor
  ~Sample(); //Canonical Destructor

  Sample &operator=(Sample const &rhs); //Canonical Copy Assignment Operator Overload

  int getFoo() const;

private:
  int _foo;

};

std::ostream &operator<<(std::ostream & o, Sample const & i);

#endif
