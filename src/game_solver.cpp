#include <iostream>

void solve_hanoi(int n, char from, char to, char aux) {
  if (n == 1) {
    std::cout << "Move disk 1 from " << from << " to " << to << std::endl;
    return;
  }

  solve_hanoi(n - 1, from, aux, to);
  std::cout << "Move disk " << n << " from " << from << " to " << to
            << std::endl;
  solve_hanoi(n - 1, aux, to, from);
}

int main() {
  int n;
  std::cout << "Enter the number of disks to solve: ";
  std::cin >> n;

  solve_hanoi(n, 'A', 'C', 'B');

  return 0;
}