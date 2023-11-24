#include <iostream>

template <typename T> void selection_sort(T *arr, const int size) {
  for (int i = 0; i < size; i++) {
    struct {
      int index;
      T value;
    } max = {i, arr[i]};

    for (int j = i + 1; j < size; j++) {
      if (arr[j] > max.value)
        max = {j, arr[j]};
    }

    std::swap(arr[i], arr[max.index]);
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};

  selection_sort(arr, std::size(arr));

  for (int i : arr) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}
