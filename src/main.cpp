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
    _string = new char[str_len + 1];
    _string[str_len] = '\0';
    while (*_string++ = *str++) {}
    _string -= str_len + 1;
  }
  string(const string& other) : _length(other._length) {
    _string = new char[other._length + 1];
    _string[_length] = '\0';
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
    _string = new char[_length + 1];
    _string[_length] = '\0';
  }
  ~string() {
    _length = 0;
    delete[] _string;
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

  void insert(size_t offset, const string& other) {
    size_t length = _length + other._length;
    char* string = new char[length];
    char* other_string = other._string;
    for (size_t i = 0; i < offset; i++)
      string[i] = _string[i];
    for (size_t i = offset; i < offset + other._length; i++)
      string[i] = other_string[i - offset];
    for (size_t i = offset + other._length; i < length; i++)
      string[i] = _string[i - (offset + other._length - 1)];

    _length = length;
    delete[] _string;
    _string = string;
    string = nullptr;
  }

  inline size_t length() const { return _length; }
  inline size_t size() const { return _length; }

  void print() const {
    std::cout << _string << '\n';
  }

private:
  size_t _length;
  char* _string;
};

int main() {
  string str1 = "hello";
  string str2 = "12";

  str1.insert(0, str2);

  str1.print();
}