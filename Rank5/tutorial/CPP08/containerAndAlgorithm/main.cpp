#include <iostream>
#include <list>
#include <map>
#include <vector>

class IOperation;

int main() {
  std::list<int> lst1;
  std::map<std::string, IOperation *> map1;
  std::vector<int> v1;
  std::vector<int> v2(42, 100);

  lst1.push_back(1);
  lst1.push_back(17);
  lst1.push_back(42);

  map1["opA"] = new OperationA;
  map2["opB"] = new OperationB;

  std::list<int>::const_iterator it;
  std::list<int>::const_iterator ite = lst1.end();

  for (it = lst1.begin(); it != ite; ++it) {
    std::cout << *it << std::endl;
  }
}
