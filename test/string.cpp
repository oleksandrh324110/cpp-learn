#include <string>

#include "gtest/gtest.h"
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

TEST(StringTest, Print) {
  string s("Hello");
  testing::internal::CaptureStdout();
  s.print();
  std::string output = testing::internal::GetCapturedStdout();
  string expected = "Hello\n";
  EXPECT_EQ(expected, output);
}