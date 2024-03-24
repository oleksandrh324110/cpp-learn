#include <gtest/gtest.h>
#include "../src/math/vector.h"

TEST(VectorTest, ConstructorTest) {
  vector<int, 3> v1{ 1, 2, 3 };
  EXPECT_EQ(v1[0], 1);
  EXPECT_EQ(v1[1], 2);
  EXPECT_EQ(v1[2], 3);
}

TEST(VectorTest, CopyConstructorTest) {
  vector<int, 3> v1{ 1, 2, 3 };
  vector<int, 3> v2(v1);
  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[1], 2);
  EXPECT_EQ(v2[2], 3);
}

TEST(VectorTest, AssignmentOperatorTest) {
  vector<int, 3> v1{ 1, 2, 3 };
  vector<int, 3> v2;
  v2 = v1;
  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[1], 2);
  EXPECT_EQ(v2[2], 3);
}

TEST(VectorTest, EqualityOperatorTest) {
  vector<int, 3> v1{ 1, 2, 3 };
  vector<int, 3> v2{ 1, 2, 3 };
  EXPECT_TRUE(v1 == v2);
}

TEST(VectorTest, ScaleTest) {
  vector<int, 3> v1{ 1, 2, 3 };
  vector<int, 3> v2 = v1.scale(2);
  EXPECT_EQ(v2[0], 2);
  EXPECT_EQ(v2[1], 4);
  EXPECT_EQ(v2[2], 6);
}

TEST(VectorTest, SumTest) {
  vector<int, 3> v1{ 1, 2, 3 };
  vector<int, 3> v2{ 4, 5, 6 };
  vector<int, 3> v3 = v1.sum(v2);
  EXPECT_EQ(v3[0], 5);
  EXPECT_EQ(v3[1], 7);
  EXPECT_EQ(v3[2], 9);
}

TEST(VectorTest, SubTest) {
  vector<int, 3> v1{ 4, 5, 6 };
  vector<int, 3> v2{ 1, 2, 3 };
  vector<int, 3> v3 = v1.sub(v2);
  EXPECT_EQ(v3[0], 3);
  EXPECT_EQ(v3[1], 3);
  EXPECT_EQ(v3[2], 3);
}

TEST(VectorTest, DotProductTest) {
  vector<int, 3> v1{ 1, 2, 3 };
  vector<int, 3> v2{ 4, 5, 6 };
  double product = v1.dot(v2);
  EXPECT_EQ(product, 32);
}

TEST(VectorTest, CrossProductTest) {
  vector<int, 3> v1{ 1, 2, 3 };
  vector<int, 3> v2{ 4, 5, 6 };
  vector<int, 3> v3 = v1.cross(v2);
  EXPECT_EQ(v3[0], -3);
  EXPECT_EQ(v3[1], 6);
  EXPECT_EQ(v3[2], -3);
}

TEST(VectorTest, LengthTest) {
  vector<int, 3> v1{ 1, 2, 3 };
  double length = v1.length();
  EXPECT_NEAR(length, 3.74166, 1e-5);
}

TEST(VectorTest, NormalizeTest) {
  vector<double, 3> v1{ 1.0, 2.0, 3.0 };
  vector<double, 3> v2 = v1.normalize();
  EXPECT_NEAR(v2[0], 0.267261, 1e-6);
  EXPECT_NEAR(v2[1], 0.534522, 1e-6);
  EXPECT_NEAR(v2[2], 0.801784, 1e-6);
}