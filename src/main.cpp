#include <iostream>
#include <vector>

void bubbleSort(std::vector<double> &arr) {
  int length = arr.size();
  while (length) {
    int maxIndex = 0;
    for (int i = 0; i < length - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        double temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        maxIndex = i;
      }
    }
    length = maxIndex;
  }
}

int main() {
  std::vector<double> arr = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

  bubbleSort(arr);

  for (auto n : arr) {
    std::cout << n << " ";
  }
}