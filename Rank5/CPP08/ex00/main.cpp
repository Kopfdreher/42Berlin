#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    std::cout << "--- Test 1: std::vector<int> (Success & Failure) ---" << std::endl;
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(15);

    try {
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "Found in vec: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        easyfind(vec, 99);
    } catch (const std::exception &e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: const std::list<int> (Const Overload) ---" << std::endl;
    int arr[] = {1, 2, 3, 4};
    const std::list<int> constLst(arr, arr + 4);

    try {
        std::list<int>::const_iterator cit = easyfind(constLst, 3);
        std::cout << "Found in const list: " << *cit << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
