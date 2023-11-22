#include <iostream>

void bubble_sort(int *arr, int size) {
  while (size) {
    int max_index = 0;
    for (int i = 1; i < size; i++) {
      if (arr[i] > arr[i - 1]) {
        std::swap(arr[i], arr[i - 1]);
        max_index = i;
      }
    }
    size = max_index;
  }
}

int main() {
  int arr[] = {1, 3, 2, 5, 4};

  bubble_sort(arr, std::size(arr));

  for (int i : arr) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}
