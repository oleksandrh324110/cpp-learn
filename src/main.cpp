#include <iostream>
#include <vector>
#include <stack>


std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
  std::vector<int> res(temperatures.size());

  struct StackElement { int index, temperature; };
  std::stack<StackElement> stack;

  for (int i = 0; i < temperatures.size(); i++) {
    while (!stack.empty() && temperatures[i] > stack.top().temperature) {
      res[stack.top().index] = i - stack.top().index;
      stack.pop();
    }

    stack.push({ i, temperatures[i] });
  }

  return res;
}

int main() {
  std::vector<int> v = { 73,74,75,71,69,72,76,73 };

  std::vector<int> res = dailyTemperatures(v);

  for (const int i : res) {
    std::cout << i << ' ';
  }
}