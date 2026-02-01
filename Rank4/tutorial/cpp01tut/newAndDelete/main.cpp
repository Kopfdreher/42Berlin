#include <iostream>
#include <string>

class Student {

public:
  Student(std::string login) : _login(login) {
    std::cout << "Student " << _login << " is born" << std::endl;
  }
  ~Student() { std::cout << "Student " << _login << " died" << std::endl; }

private:
  std::string _login;
};

int main() {
  Student *jim = new Student("amargolo");
  delete jim;
  Student bob = Student("sgavrilo");
}

/* allocate arrays

int main() {
	Student *students = new Student[42];

	delete [] students;
}

*/
