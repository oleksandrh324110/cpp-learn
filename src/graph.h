#pragma once

#include <iostream>
#include <vector>

#include "queue.h"

class graph {
 public:
  graph() {
    std::cin >> _size;

    std::cin >> _start;
    _start--;

    _data.reserve(_size);
    for (size_t i = 0; i < _size; i++) {
      _data[i].reserve(_size);
      for (size_t j = 0; j < _size; j++) {
        bool temp;
        std::cin >> temp;
        _data[i][j] = temp;
      }
    }
  }

  void distances() {
    std::vector distances(_size, -1);
    distances[_start] = 0;

    queue<size_t> q;
    q.push(_start);

    while (!q.empty()) {
      size_t u = q.pop();
      for (size_t v = 0; v < _size; v++) {
        if (_data[u][v] == 1 && distances[v] == -1) {
          distances[v] = distances[u] + 1;
          q.push(v);
        }
      }
    }

    for (int d : distances) {
      std::cout << d << ' ';
    }
    std::cout << '\n';
  }

 private:
  size_t _size;
  size_t _start;
  std::vector<std::vector<bool>> _data;
};
