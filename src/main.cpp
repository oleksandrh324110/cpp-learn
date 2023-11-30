#include <iostream>
#include <vector>

void merge(int arr[], int left, int middle, int right) {
  int n1 = middle - left + 1;
  int n2 = right - middle;

  int leftArray[n1];
  int rightArray[n2];

  for (int i = 0; i < n1; i++)
    leftArray[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    rightArray[j] = arr[middle + 1 + j];

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2) {
    if (leftArray[i] <= rightArray[j])
      arr[k] = leftArray[i++];
    else
      arr[k] = rightArray[j++];
    k++;
  }

  while (i < n1) arr[k++] = leftArray[i++];
  while (j < n2) arr[k++] = rightArray[j++];
}

void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int middle = left + (right - left) / 2;

    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);

    merge(arr, left, middle, right);
  }
}

int main() {
  int arr[] = { 5, 4, 3, 2, 1 };

  mergeSort(arr, 0, std::size(arr) - 1);

  for (int i : arr) {
    std::cout << i << " ";
  } std::cout << '\n';
}
