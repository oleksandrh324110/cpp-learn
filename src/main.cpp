#include <iostream>

char *strcpy(char *str1, const char *str2) {
  char *saved = str1;
  while (*str2) {
    *str1++ = *str2++;
  }
  *str1 = '\0';
  return saved;
}

int main() {
  char str1[] = "";
  char str2[] = "Hello World!";

  strcpy(str1, str2);

  std::cout << "str1: " << str1 << '\n' << "str2: " << str2 << '\n';
}