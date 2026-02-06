class Quadruped {

private:
  std::string _name; // Only accessible from an Quadruped object

protected:
  leg legs[4]; // Accessible from an Quadruped or derived object

public:
  void run(); // Accessible from wherever
};

class Dog : public Quadruped {}; // Can access run() and legs

int main() {} // Can only access run()
