#include <string>

class Zombie {

public:
  Zombie();
  Zombie(std::string _name);
  ~Zombie();

  void announce(void);
	void setName(std::string name);

private:
  std::string _name;

};

Zombie *zombieHorde(int N, std::string name);
