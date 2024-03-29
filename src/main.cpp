#include <iostream>

size_t strlen(const char* str) {
  size_t len = 0;
  while (*str++) len++;
  return len;
}

class string {
public:
  string(const char* str) {
    size_t str_len = strlen(str);
    _length = str_len;
    _string = new char[str_len];
    while (*_string++ = *str++) {}
    _string -= str_len + 1;
  }
  string(const string& other) : _length(other._length) {
    _string = new char[other._length];
    char* other_string = other._string;
    while (*_string++ = *other_string++) {}
    _string -= _length + 1;
  }
  string(string&& other) : _length(other._length), _string(other._string) {
    other._length = 0;
    other._string = nullptr;
  }
  string(size_t size) {
    _length = size;
    _string = new char[_length];
  }

  bool operator==(const string& other) const {
    if (_length != other._length)
      return false;
    for (size_t i = 0; i < _length; i++)
      if (_string[i] != other._string[i])
        return false;
    return true;
  }

  string operator+(const string& other) const {
    string res(_length + other._length);
    char* string_copy = _string;
    char* other_string = other._string;
    while (*res._string++ = *string_copy++) {}
    res._string--;
    while (*res._string++ = *other_string++) {}
    res._string -= res._length + 1;
    return res;
  }

  inline size_t length() const { return _length; }

  void print() const {
    std::cout << _string << '\n';
  }

private:
  size_t _length;
  char* _string;
};

int main() {
  string str = "hello ";
  string str1 = str;

  string str2 = str + str1;

  str2.print();
}