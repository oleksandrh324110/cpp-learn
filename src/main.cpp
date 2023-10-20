#include <ctime>
#include <iostream>
#include <random>

int main() {
  srand(time(nullptr));

  int arr[9]{};

  for (auto &n : arr)
    n = rand() % 10;

  for (auto &n : arr)
    std::cout << n << " ";
  std::cout << '\n';

  int searchNumber = rand() % 10;
  for (auto &n : arr)
    if (n == searchNumber) {
      std::cout << "Number " << searchNumber << " is found" << std::endl;
      return 0;
    }
  std::cout << "Number " << searchNumber << " isn't found" << std::endl;
}