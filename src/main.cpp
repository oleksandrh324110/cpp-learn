#include <iostream>
#include <typeinfo>

class fraction {
public:
  fraction(double numerator, double denominator) : _value(numerator / denominator) {}
  fraction(const fraction& other) : _value(other.value()) {}
  fraction(double value) : _value(value) {}
  fraction() : _value(0) {}
  fraction& operator=(const fraction& other) {
    if (this != &other)
      _value = other.value();
    return *this;
  }
  ~fraction() {}

  double value() const { return _value; }

  fraction sum(const fraction& other) const { return fraction(_value + other.value()); }
  fraction sub(const fraction& other) const { return fraction(_value - other.value()); }
  fraction mult(const fraction& other) const { return fraction(_value * other.value()); }
  fraction div(const fraction& other) const { return fraction(_value / other.value()); }
  fraction operator+(const fraction& other) const { return sum(other); }
  fraction operator-(const fraction& other) const { return sub(other); }
  fraction operator*(const fraction& other) const { return mult(other); }
  fraction operator/(const fraction& other) const { return div(other); }

  void print() const {
    std::cout << _value << '\n';
  }

private:
  double _value;
};

fraction operator+(double value, const fraction& other) { return other.sum(value); }
fraction operator-(double value, const fraction& other) { return other.sub(value); }
fraction operator*(double value, const fraction& other) { return other.mult(value); }
fraction operator/(double value, const fraction& other) { return other.div(value); }

int main() {
  fraction f = fraction(1);

  const std::type_info& type_id = typeid(f);

  std::cout << "The type of f is: " << type_id.name() << "\n";
}