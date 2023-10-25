#include <iostream>

bool m_strcmp(const char *s1, const char *s2) {
  while (*s1)
    if (*s1++ != *s2++)
      return false;

  return !*s2;
}

int main() { std::cout << m_strcmp("Hello", "Hello") << '\n'; }