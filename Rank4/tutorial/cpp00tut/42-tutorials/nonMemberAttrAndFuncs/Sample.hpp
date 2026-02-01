#ifndef SAMPLE_H
#define SAMPLE_H

class Sample {
public:
  Sample();
  ~Sample();

  static int getMbInst();

private:
  static int _mbInst;
};

#endif
