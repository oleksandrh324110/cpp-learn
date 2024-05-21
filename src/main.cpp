#include <iostream>

#include "hashmap.h"

int main(void) {
  std::hashmap<std::string, int> map(5);

  map.insert("first insert", 1);
  map.insert("second insert", 2);
  map["first bracket"] = 3;
  map["second bracket"] = 4;

  map.print();
  std::cout << '\n';

  map.remove("second insert");
  map.remove("second bracket");

  map.print();

  std::cout << '\n' << map.contains("first insert") << '\n';
}
