#include "string.h"

size_t strlen(const char* str) {
  size_t len = 0;
  while (*str++) len++;
  return len;
}

string::string() {
  _length = 0;
  _string = nullptr;
}

string::string(const char* str) {
  size_t str_len = strlen(str);
  _length = str_len;
  _string = new char[str_len + 1];
  _string[str_len] = '\0';
  while (*_string++ = *str++) {}
  _string -= str_len + 1;
}
string::string(const string& other) : _length(other._length) {
  _string = new char[other._length + 1];
  _string[_length] = '\0';
  char* other_string = other._string;
  while (*_string++ = *other_string++) {}
  _string -= _length + 1;
}
string::string(string&& other) : _length(other._length), _string(other._string) {
  other._length = 0;
  other._string = nullptr;
}
void string::operator=(string& other) {
  _length = other._length;
  _string = new char[other._length + 1];
  _string[_length] = '\0';
  char* other_string = other._string;
  while (*_string++ = *other_string++) {}
  _string -= _length + 1;
}
void string::operator=(string&& other) {
  _length = other._length;
  _string = other._string;
  other._length = 0;
  other._string = nullptr;
}
string::string(size_t size) {
  _length = size;
  _string = new char[_length + 1];
  _string[_length] = '\0';
}
string::~string() {
  _length = 0;
  delete[] _string;
}

char& string::operator[](size_t index) const {
  return _string[index];
}

bool string::operator==(const string& other) const {
  if (_length != other._length)
    return false;
  for (size_t i = 0; i < _length; i++)
    if (_string[i] != other[i])
      return false;
  return true;
}
bool string::operator==(const std::string& std_other) const {
  if (_length != std_other.length())
    return false;
  for (size_t i = 0; i < _length; i++)
    if (_string[i] != std_other[i])
      return false;
  return true;
}

bool string::operator!=(const string& other) const {
  return !(*this == other);
}

string string::operator+(const string& other) const {
  string res(_length + other._length);
  char* string_copy = _string;
  char* other_string = other._string;
  while (*res._string++ = *string_copy++) {}
  res._string--;
  while (*res._string++ = *other_string++) {}
  res._string -= res._length + 1;
  return res;
}

void string::insert(size_t offset, const string& other) {
  if (offset > _length)
    throw std::invalid_argument("Offset is out of range");

  size_t length = _length + other._length;
  char* string = new char[length];
  char* other_string = other._string;

  for (size_t i = 0; i < offset; i++)
    *string++ = *_string++;
  while (*string++ = *other_string++) {}
  string--;
  while (*string++ = *_string++) {}
  string -= length + 1;
  _string -= _length + 1;

  _length = length;
  _string = string;
  string = nullptr;
}

string string::substr(size_t index, size_t length) const {
  if (index >= _length)
    throw std::invalid_argument("Index is out of range");
  if (index + length > _length)
    throw std::invalid_argument("index + length is out of range");

  length = length ? length : _length - index;
  string res(length);
  for (size_t i = 0; i < length; i++) {
    res[i] = _string[index + i];
  } return res;
}

inline const char* string::c_str() const {
  return _string;
}

void string::print() const {
  std::cout << _string << '\n';
}

void operator<<(std::ostream& stream, const string& str) {
  stream << str.c_str();
}

void operator>>(std::istream& stream, string& str) {
  std::string input;
  std::getline(stream, input);
  str = string(input.c_str());
}