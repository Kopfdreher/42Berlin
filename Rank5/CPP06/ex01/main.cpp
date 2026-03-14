#include "defines.hpp"

int main(int argc, char **argv) {
  Data myData;

  if (argc == 2) {
    myData.input = argv[1];
    std::cout << "--- Original Data ---\n";
    std::cout << "Address: " << &myData << "\n";
    std::cout << "Value: " << myData.input << "\n";

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "\n--- Serialized UINTPTR_T ---\n";
    std::cout << "Value: " << raw << "\n";

    Data *deserializedData = Serializer::deserialize(raw);
    std::cout << "\n--- Deserialized Data ---\n";
    std::cout << "Address: " << deserializedData << "\n";
    std::cout << "Value: " << deserializedData->input << "\n";

    if (&myData == deserializedData)
      std::cout << "\n--- Deserialization Successful ---\n";
    else
      std::cout << "\n--- Deserialization Failed ---\n";
  }
}
