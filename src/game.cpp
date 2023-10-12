#include <array>
#include <iostream>
#include <vector>

void print_tower(const std::vector<char> &tower) {
  for (auto i : tower) {
    std::cout << (int)i << " ";
  }
}

void swap_disks(std::vector<char> &from, std::vector<char> &to) {
  to.push_back(from.back());
  from.pop_back();
}

void hanoi_tower(unsigned short n) {
  std::array<std::vector<char>, 3> towers{};

  for (int i = 0; i < n; i++) {
    towers[0].push_back(n - i);
  }

  char from, to;
  while (towers[2].size() < n && towers[1].size() < n) {
    std::cout << "tower a: ";
    print_tower(towers[0]);
    std::cout << "\ntower b: ";
    print_tower(towers[1]);
    std::cout << "\ntower c: ";
    print_tower(towers[2]);

    std::cout << "\n\n";

    std::cout << "Move from: ";
    std::cin >> from;
    std::cout << "Move to: ";
    std::cin >> to;

    std::cout << "\n";

    char diskFrom = std::tolower(from) - 'a';
    char diskTo = std::tolower(to) - 'a';

    if (diskFrom >= 0 && diskFrom <= 2 && diskTo >= 0 && diskTo <= 2) {
      if (!towers[diskFrom].empty()) {
        if (towers[diskTo].empty() ||
            towers[diskFrom].back() < towers[diskTo].back()) {
          swap_disks(towers[diskFrom], towers[diskTo]);
        }
      }
    }
  }

  std::cout << "You solved it!\n";
}

int main() {
  std::cout << "Enter the number of disks to play: ";
  unsigned short n;
  std::cin >> n;
  std::cout << "\n";

  hanoi_tower(n);
}