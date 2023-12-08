#include <iostream>
#include <vector>
#include <unordered_set>

int longestConsecutive(std::vector<int>& nums) {
  std::unordered_set<int> set;

  for (const int num : nums) {
    set.insert(num);
  }

  int max = 0;
  while (set.size()) {
    const int num = *set.begin();

    int max_buff = 1;
    set.erase(num);

    for (int i = 1; set.count(num + i); i++) {
      max_buff++;
      set.erase(num + i);
    }
    for (int i = 1; set.count(num - i); i++) {
      max_buff++;
      set.erase(num - i);
    }
    max = std::max(max, max_buff);
  }

  return max;
}

int main() {
  std::vector<int> v = { 4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3 };

  std::cout << longestConsecutive(v) << '\n';
}
