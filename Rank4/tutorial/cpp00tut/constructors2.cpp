#include <iostream>

class Car {
public:
  Car();
  Car(std::string pbrand, std::string pmodel, int pyear);
  std::string brand;
  std::string model;
  int year;
};

Car::Car(void) {
  std::cout << "Hello world !" << std::endl;
  brand = "Opel";
  model = "Corsa";
  year = 1999;
  return;
}

Car::Car(std::string pbrand, std::string pmodel, int pyear) {
  brand = pbrand;
  model = pmodel;
  year = pyear;
  return;
}

int main() {
  Car car1;
  Car car2("Ford", "Mustang", 1969);

  std::cout << car1.brand << " " << car1.model << " " << car1.year << std::endl;
  std::cout << car2.brand << " " << car2.model << " " << car2.year << std::endl;
  return 0;
}
