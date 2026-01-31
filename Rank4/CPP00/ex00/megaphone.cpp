#include <cctype>
#include <iostream>

void put_upper_case(char **argv) {
  int i;
  int j;

  i = 0;
  while (argv[++i]) {
    j = -1;
    while (argv[i][++j]) {
      if (std::isalpha(argv[i][j])) {
        argv[i][j] = std::toupper(argv[i][j]);
      }
    }
		std::cout << argv[i];
  }
}

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  } else {
    put_upper_case(argv);
  }
}
