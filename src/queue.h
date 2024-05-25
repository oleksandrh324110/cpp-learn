#include <iostream>
#include <string>
#include <vector>

template <typename T>
class queue {
 private:
  std::vector<T> data;

 public:
  queue() {}
  ~queue() {}

  void push(T x) { data.push_back(x); }
  T pop() {
    T temp = data[0];
    data.erase(data.begin());
    return temp;
  }

  T front() { return data.front(); }
  T back() { return data.back(); }

  size_t size() { return data.size(); }
  bool empty() { return data.empty(); }
  void clear() { data.clear(); }
};
