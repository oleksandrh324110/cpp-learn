#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
  std::set<std::vector<int>> set;

  std::unordered_map<int, int> map;

  for (int i = 0; i < nums.size(); i++) {
    map[nums[i]] = i;
  }

  for (int i = 0; i < nums.size(); i++) {
    int sum_of_others = -nums[i];

    for (int j = i + 1; j < nums.size(); j++) {
      int index_of_third = map[sum_of_others - nums[j]];

      if (index_of_third == 0 || i == index_of_third || j == index_of_third) break;

      std::vector<int> values = { nums[i], nums[j], nums[index_of_third] };
      std::sort(values.begin(), values.end());

      set.insert(values);
    }
  }

  for (const auto& v : set) {
    for (const auto& i : v) {
      std::cout << i << " ";
    } std::cout << std::endl;
  }

  return std::vector<std::vector<int>>(set.begin(), set.end());
}

int main() {
  std::vector<int> v = { -1,0,1,2,-1,-4 };

  threeSum(v);
}
