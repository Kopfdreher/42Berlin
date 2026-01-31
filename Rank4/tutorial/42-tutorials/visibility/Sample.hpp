#ifndef SAMPLE_H
#define SAMPLE_H

class Sample {
public:
  int publicFoo;

  Sample();
  ~Sample();
  void publicBar() const;

private:
  int _privateFoo;

  void _privateBar() const;
};

#endif
