#include <iostream>
#include <sstream>
#include <stdexcept>

size_t _strlen(const char* str);

class string {
public:
  string();
  string(const char* str);
  string(const string& other);
  string(string&& other);
  void operator=(string& other);
  void operator=(string&& other);
  string(size_t size);
  string(int number);
  ~string();

  char& operator[](size_t index);
  char operator[](size_t index) const;
  char& at(size_t index);
  char at(size_t index) const;
  bool operator==(const string& other) const;
  bool operator==(const std::string& std_string) const;
  bool operator!=(const string& other) const;
  bool operator!=(const std::string& std_string) const;
  string operator+(const string& other) const;
  void insert(size_t offset, const string& other);
  string substr(size_t index, size_t length = 0) const;
  bool contains(const string& other) const;

  operator int() const;

  inline size_t length() const { return _length; };
  inline size_t size() const { return _length; };

  inline const char* c_str() const { return _string; };

  void print() const;

private:
  size_t _length;
  char* _string;
};

void operator<<(std::ostream& stream, const string& str);
void operator>>(std::istream& stream, string& str);