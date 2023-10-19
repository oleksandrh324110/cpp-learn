#include <ctime>
#include <iostream>
#include <random>

int main() {
  srand(time(nullptr));

  int arr[3][4] = {};

  int zeroCount = 0;

  for (auto &i : arr)
    for (auto &j : i)
      j = rand() % 10;

  for (auto &i : arr) {
    for (auto &j : i)
      std::cout << j << ' ';
    std::cout << '\n';
  }

  for (auto &i : arr)
    for (auto &j : i)
      if (j == 0)
        zeroCount++;

  std::cout << "Zero count: " << zeroCount << '\n';
}