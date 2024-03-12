#include <iostream>

class fraction {
public:
  fraction(double numerator, double denominator) {
    _value = numerator / denominator;
  }

private:
  double _value;
};

int main() {
  fraction f = fraction(1, 1);
}
