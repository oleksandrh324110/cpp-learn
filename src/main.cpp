#include <iostream>
#include <vector>
#include <numeric>

int main(void) {
  size_t size; std::cout << "Enter size: "; std::cin >> size;

  std::vector<int> arr(size);

  std::cout << "Enter elements: ";
  for (size_t i = 0; i < size; i++)
    std::cin >> arr[i];

  std::cout << "Multiplication is: " << std::accumulate(arr.begin(), arr.end(), 1, std::multiplies<int>{}) << '\n';
}