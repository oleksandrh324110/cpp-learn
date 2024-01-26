#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map> 

int lengthOfLongestSubstring(std::string s) {
  std::unordered_map<char, int> map;

  int max = 0;
  int buffMax = 0;

  for (int i = 0; i < s.length(); i++) {
    map[s[i]] = i;
    buffMax++;

    for (int j = i + 1; j < s.length(); j++) {
      if (map.count(s[j])) {
        i = map[s[j]];
        break;
      }
      map[s[j]] = j;
      buffMax++;
    }

    max = std::max(max, buffMax);
    buffMax = 0;
    map.clear();
  }

  return max;
}

int main() {
  std::cout << lengthOfLongestSubstring("dvdf") << '\n';
}