#include <gtest/gtest.h>
#include <sstream>
#include <string>

#include "../src/string.h"

TEST(StringTest, CharConstructor) {
  string s("Hello");
  EXPECT_EQ((size_t)5, s.length());
}

TEST(StringTest, CopyConstructor) {
  string s1("Hello");
  string s2(s1);
  string expected = "Hello";
  EXPECT_EQ(expected, s2);
}

TEST(StringTest, MoveConstructor) {
  string s1("Hello");
  string s2(std::move(s1));
  string expected = "Hello";
  EXPECT_EQ(expected, s2);
}

TEST(StringTest, IntConstructor) {
  int number1 = 123;
  string s1(number1);
  EXPECT_STREQ("123", s1.c_str());

  int number2 = -456;
  string s2(number2);
  EXPECT_STREQ("-456", s2.c_str());

  int number3 = 0;
  string s3(number3);
  EXPECT_STREQ("0", s3.c_str());
}

TEST(StringTest, EqualityOperator) {
  string s1("Hello");
  string s2("Hello");
  EXPECT_EQ(s1, s2);
  string s3("World");
  EXPECT_NE(s1, s3);
  std::string str = "Hello";
  EXPECT_EQ(s1, str);
}

TEST(StringTest, AdditionOperator) {
  string s1("Hello");
  string s2("World");
  string s3 = s1 + s2;
  string expected = "HelloWorld";
  EXPECT_EQ(expected, s3);
  EXPECT_EQ(expected.length(), s3.length());
}

TEST(StringTest, Insert) {
  string s1("Hello");
  string s2("World");
  s1.insert(5, s2);
  string expected = "HelloWorld";
  EXPECT_EQ(expected, s1);
  EXPECT_EQ(expected.length(), s1.length());
}

TEST(StringTest, Substr) {
  string s("HelloWorld");
  string sub = s.substr(5, 5);
  string expected = "World";
  EXPECT_EQ(expected, sub);
  EXPECT_EQ(expected.length(), sub.length());
}

TEST(StringTest, Contains) {
  string s("Hello, World!");

  string s1("Hello");
  EXPECT_TRUE(s.contains(s1));

  string s2("World!");
  EXPECT_TRUE(s.contains(s2));

  string s3("Goodbye");
  EXPECT_FALSE(s.contains(s3));

  string s4(" ");
  EXPECT_TRUE(s.contains(s4));

  string s5("");
  EXPECT_TRUE(s.contains(s5));
}

TEST(StringTest, IntConversion) {
  string s1 = "123";
  int expected1 = 123;
  EXPECT_EQ(expected1, (int)s1);

  string s2 = "-456";
  int expected2 = -456;
  EXPECT_EQ(expected2, (int)s2);

  string s3 = "0";
  int expected3 = 0;
  EXPECT_EQ(expected3, (int)s3);
}

TEST(StringTest, Print) {
  string s("Hello");
  testing::internal::CaptureStdout();
  s.print();
  std::string output = testing::internal::GetCapturedStdout();
  string expected = "Hello\n";
  EXPECT_EQ(expected, output);
}

TEST(StringTest, OutputStreamOperator) {
  string s("Hello");
  std::ostringstream os;
  os << s;
  std::string expected = "Hello";
  EXPECT_EQ(expected, os.str());
}

TEST(StringTest, InputStreamOperator) {
  std::istringstream is("Hello");
  string s;
  is >> s;
  string expected = "Hello";
  EXPECT_EQ(expected, s);
}