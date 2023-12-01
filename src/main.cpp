#include <iostream>
#include <vector>

#define size 3

struct pos {
  int x, y;
};

// tl = top_left, br = bottom_right
int find_matrix_det(
  int m[size][size],
  pos top_left = { 0, 0 },
  pos bottom_right = { size, size })
{
  if (bottom_right.x - top_left.x == 2 && bottom_right.y - top_left.y == 2) {
    return m[top_left.x][top_left.y] * m[top_left.x + 1][top_left.y + 1] -
      m[top_left.x + 1][top_left.y] * m[top_left.x][top_left.y + 1];
  }
}

int main() {
  int arr[size][size] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

  std::cout << find_matrix_det(arr) << '\n';
}
