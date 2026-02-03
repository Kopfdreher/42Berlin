#include <string>

#ifndef WEAPON_H
#define WEAPON_H

class Weapon {

public:
  Weapon(std::string type);
  ~Weapon();

  const std::string &getType();
  void setType(std::string type);

private:
  std::string _type;

  Weapon();
};

#endif
