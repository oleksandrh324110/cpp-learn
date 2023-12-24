#include <iostream>
#include <vector>
#include <stack>

int evalRPN(std::vector<std::string>& tokens) {
  std::stack<int> stack;

  for (const std::string& s : tokens) {
    if (s.size() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')) {
      int value_to_push = stack.top();
      stack.pop();
      if (s[0] == '+')
        value_to_push += stack.top();
      else if (s[0] == '-')
        value_to_push -= stack.top();
      else if (s[0] == '*')
        value_to_push *= stack.top();
      else if (s[0] == '/')
        value_to_push = stack.top() / value_to_push;
      stack.pop();
      stack.push(value_to_push);
    } else {
      stack.push(std::stoi(s));
    }
  } return stack.top();
}

int main() {
  std::vector<std::string> str = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
  std::cout << evalRPN(str);
}