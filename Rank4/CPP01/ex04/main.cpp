#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
bool openFiles(std::ifstream &inFile, std::ofstream &outFile, char **argv) {

  inFile.open(argv[1]);
  if (!inFile.is_open()) {
    std::cerr << "Error: Could not open input file." << std::endl;
    return (false);
  }
  std::string outName = std::string(argv[1]) + ".replace";
  outFile.open(outName.c_str());
  if (!outFile.is_open()) {
    std::cerr << "Error: Could not open output file." << std::endl;
    return (false);
  }
  return (true);
}

void fillOutFile(const std::string &inString, const std::string &s1, const std::string &s2,
                 std::ofstream &outFile) {

  size_t pos = 0;
  size_t nPos;

  while (1) {
    nPos = inString.find(s1, pos);
    if (nPos == std::string::npos)
      break;
    else {
      outFile << inString.substr(pos, nPos - pos);
      outFile << s2;
      pos = nPos + s1.length();
    }
  }
  outFile << inString.substr(pos, inString.length() - pos);
}

bool inputValid(int argc, char **argv) {

  if (argc != 4) {
    std::cerr << "Invalid Arg-Count, usage: ./ex04 <filename> <s1> <s2>"
              << std::endl;
    return (false);
  }
  if (argv[2][0] == '\0') {
    std::cerr
        << "Invalid empty string in s1, usage: ./ex04 <filename> <s1> <s2>"
        << std::endl;
    return (false);
  }
  return (true);
}

int main(int argc, char **argv) {

  if (!inputValid(argc, argv))
    return (1);

  // opening files
  std::ifstream inFile;
  std::ofstream outFile;
  if (!openFiles(inFile, outFile, argv))
    return (1);

  // putting inFile content into a string
  std::stringstream buffer;
  buffer << inFile.rdbuf();
  std::string inString = buffer.str();

  fillOutFile(inString, argv[2], argv[3], outFile);
}
