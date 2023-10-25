#include <iostream>

void m_strcat(char *to, const char *from) {
  while (*to) {
    to++;
  }
  while (*from) {
    *to++ = *from++;
  }
  *to = 0;
}

int main() {
  char str1[30] = "Hello ";
  const char *str2 = "World!!!";

  std::cout << "str1 before m_strcat: " << str1 << '\n';

  m_strcat(str1, str2);

  std::cout << "str1 after m_strcat: " << str1 << '\n';
}