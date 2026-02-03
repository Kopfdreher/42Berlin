#ifndef SAMPLE_H
#define SAMPLE_H

class Sample {

public:
  Sample();
  ~Sample();

  void bar(char const c) const;
  void bar(int const n) const;
  void bar(float const z) const;
  void bar(Sample const &i) const;
};

#endif
