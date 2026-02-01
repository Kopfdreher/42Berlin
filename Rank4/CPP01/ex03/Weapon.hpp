#include <string>

#ifndef WEAPON_H
#define WEAPON_H

class Weapon {

public:
  Weapon(std::string type);
  ~Weapon();

  std::string getType() const &;
  void setType(std::string type);

private:
  std::string _type;

  Weapon();
};

#endif
