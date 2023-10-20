#include "ansi.cpp"
#include <iostream>

struct Min {
  int index, value;
};

void selectionSort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    std::cout << '\n';

    Min min = {i, arr[i]};

    for (int j = i + 1; j < size; j++) {
      if (arr[j] < min.value) {
        min = {j, arr[j]};
      }
    }

    if (min.index != i) {
      int temp = arr[i];
      arr[i] = arr[min.index];
      arr[min.index] = temp;
    }

    for (int k = 0; k < size; k++) {
      if (k == i) {
        std::cout << ANSI::bold << ANSI::red << arr[k] << ANSI::reset << ' ';
      } else if (k == min.index) {
        std::cout << ANSI::bold << ANSI::green << arr[k] << ANSI::reset << ' ';
      } else
        std::cout << ANSI::bold << arr[k] << ANSI::reset << ' ';
    }
  }
}

int main() {
  int arr[] = {3, 5, 2, 7, 6, 4, 1};

  for (int &i : arr) {
    std::cout << ANSI::bold << i << ANSI::reset << ' ';
  }

  selectionSort(arr, sizeof(arr) / sizeof(arr[0]));
}