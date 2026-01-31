#ifndef SAMPLE_H
#define SAMPLE_H

class Sample {
public:
  Sample();
  ~Sample();

  int getFoo() const;
  void setFoo(int value);

private:
  int _foo;
};

#endif
