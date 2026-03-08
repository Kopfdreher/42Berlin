#include <stdexcept>

void test1() {
  try {
    // Do some stuff here
    if (/* there's an error */) {
      throw std::exception();
    } else {
      // Do some more stuff
    }
  } catch (std::exception e) {
    // Handle the error here
  }
}

void test2() {
  // Do some stuff here
  if (/* there's an error */) {
    throw std::exception();
  } else {
    // Do some more stuff
  }
}

void test3() {
  try {
    test2();
  } catch (std::exception &e) {
    // Handle error
  }
}

void test4() {
  class PEBKACException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return ("Problem exists between keyboard and chair");
    }
  };

  try {
    test3();
  }
  catch (PEBKACException &e) {
    // Handle the fact that the user is an idiot
  }
  catch (std::exception &e) {
    // Handle other exceptions that are like std::exception
  }
}
