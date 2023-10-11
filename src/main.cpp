#include <iostream>
#include <vector>

void print_tower(const std::vector<char> &tower) {
  std::cout << tower.size();
  for (auto i : tower) {
    std::cout << (int)i << " ";
  }
}

void hanoi_tower(char n) {
  std::vector<char> tower_a((int)n);
  std::vector<char> tower_b;
  std::vector<char> tower_c;

  std::cout << (int)n;

  for (char i = 0; i < n; i++) {
    tower_a.push_back(n - i);
  }

  char from, to;
  while (tower_c.size() < n) {
    std::cout << "tower a: ";
    print_tower(tower_a);

    return;
    std::cout << "\ntower b: ";
    print_tower(tower_b);
    std::cout << "\ntower c: ";
    print_tower(tower_c);

    std::cout << "\n\n";

    std::cout << "Move from: ";
    std::cin >> from;
    std::cout << "Move to: ";
    std::cin >> to;

    std::cout << from << ' ' << to << '\n';
  }
}

int main() {
  std::cout << "Enter the number of disks: ";
  char n;
  std::cin >> n;

  hanoi_tower(n);
}