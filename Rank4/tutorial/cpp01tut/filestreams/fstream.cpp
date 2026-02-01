#include <iostream>
#include <fstream>

int main() {
	std::ifstream ifs("numbers");
	unsigned int dst = 0;
	unsigned int dst2 = 0;
	ifs >> dst >> dst2;

	std::cout << dst << " " << dst2 << std::endl;
	ifs.close();

	std::ofstream ofs("test.out");

	ofs << "i like ponies a whole damn lot" << std::endl;
	ofs.close();
}
