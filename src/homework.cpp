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
        std::cout << "\033[31m" << arr[k] << "\033[0m ";
      } else if (k == min.index) {
        std::cout << "\033[32m" << arr[k] << "\033[0m ";
      } else
        std::cout << arr[k] << ' ';
    }
  }
}

int main() {
  int arr[] = {3, 5, 2, 7, 6, 4, 1};

  for (int &i : arr) {
    std::cout << i << ' ';
  }

  selectionSort(arr, sizeof(arr) / sizeof(arr[0]));
}