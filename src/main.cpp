#include <iostream>

#include "math/vector.h"
#include "math/matrix.h"

int main() {
  vector<float, 2> v1 = { 0, 1 };
  float arr[2] = { 1, 0 };
  v1 = arr;

  v1 = v1
    .normalize()
    .scale(2)
    .add({ -1, 1 })
    .sub({ 1, 0 });

  v1.print(); // 0 1 
  std::cout << v1.dot({ 0, -1 }) << '\n'; // -1
}