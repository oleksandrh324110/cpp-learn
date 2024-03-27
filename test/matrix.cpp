#include <gtest/gtest.h>
#include "../src/math/matrix.h"

TEST(MatrixTest, ConstructorTest) {
  matrix<int, 2, 2> m1{ {1, 2}, {3, 4} };
  EXPECT_EQ(m1[0][0], 1);
  EXPECT_EQ(m1[0][1], 2);
  EXPECT_EQ(m1[1][0], 3);
  EXPECT_EQ(m1[1][1], 4);
}

TEST(MatrixTest, CopyConstructorTest) {
  matrix<int, 2, 2> m1{ {1, 2}, {3, 4} };
  matrix<int, 2, 2> m2(m1);
  EXPECT_EQ(m2[0][0], 1);
  EXPECT_EQ(m2[0][1], 2);
  EXPECT_EQ(m2[1][0], 3);
  EXPECT_EQ(m2[1][1], 4);
}

TEST(MatrixTest, AssignmentOperatorTest) {
  matrix<int, 2, 2> m1{ {1, 2}, {3, 4} };
  matrix<int, 2, 2> m2;
  m2 = m1;
  EXPECT_EQ(m2[0][0], 1);
  EXPECT_EQ(m2[0][1], 2);
  EXPECT_EQ(m2[1][0], 3);
  EXPECT_EQ(m2[1][1], 4);
}

TEST(MatrixTest, EqualityOperatorTest) {
  matrix<int, 2, 2> m1{ {1, 2}, {3, 4} };
  matrix<int, 2, 2> m2{ {1, 2}, {3, 4} };
  EXPECT_TRUE(m1 == m2);
}

TEST(MatrixTest, AdditionTest) {
  matrix<int, 2, 2> m1{ {1, 2}, {3, 4} };
  matrix<int, 2, 2> m2{ {5, 6}, {7, 8} };
  matrix<int, 2, 2> m3 = m1 + m2;
  EXPECT_EQ(m3[0][0], 6);
  EXPECT_EQ(m3[0][1], 8);
  EXPECT_EQ(m3[1][0], 10);
  EXPECT_EQ(m3[1][1], 12);
}

TEST(MatrixTest, SubtractionTest) {
  matrix<int, 2, 2> m1{ {5, 6}, {7, 8} };
  matrix<int, 2, 2> m2{ {1, 2}, {3, 4} };
  matrix<int, 2, 2> m3 = m1 - m2;
  EXPECT_EQ(m3[0][0], 4);
  EXPECT_EQ(m3[0][1], 4);
  EXPECT_EQ(m3[1][0], 4);
  EXPECT_EQ(m3[1][1], 4);
}

TEST(MatrixTest, MultiplicationTest) {
  matrix<int, 2, 2> m1{ {1, 2}, {3, 4} };
  matrix<int, 2, 2> m2{ {5, 6}, {7, 8} };
  matrix<int, 2, 2> m3 = m1 * m2;
  EXPECT_EQ(m3[0][0], 19);
  EXPECT_EQ(m3[0][1], 22);
  EXPECT_EQ(m3[1][0], 43);
  EXPECT_EQ(m3[1][1], 50);
}

TEST(MatrixTest, ScaleByScalarTest) {
  matrix<int, 2, 2> m1{ {1, 2}, {3, 4} };
  matrix<int, 2, 2> m2 = m1.scale(2);
  EXPECT_EQ(m2[0][0], 2);
  EXPECT_EQ(m2[0][1], 4);
  EXPECT_EQ(m2[1][0], 6);
  EXPECT_EQ(m2[1][1], 8);
}

TEST(MatrixTest, DivisionByScalarTest) {
  matrix<double, 2, 2> m1{ {2.0, 4.0}, {6.0, 8.0} };
  matrix<double, 2, 2> m2 = m1 / 2.0;
  EXPECT_NEAR(m2[0][0], 1.0, 1e-6);
  EXPECT_NEAR(m2[0][1], 2.0, 1e-6);
  EXPECT_NEAR(m2[1][0], 3.0, 1e-6);
  EXPECT_NEAR(m2[1][1], 4.0, 1e-6);
}

TEST(MatrixTest, DeterminantTest) {
  matrix<int, 2, 2> m1{ {1, 2}, {3, 4} };
  EXPECT_EQ(m1.det(), -2);
}

TEST(MatrixTest, TransposeTest) {
  matrix<int, 2, 2> m1{ {1, 2}, {3, 4} };
  matrix<int, 2, 2> m2 = m1.transpose();
  EXPECT_EQ(m2[0][0], 1);
  EXPECT_EQ(m2[0][1], 3);
  EXPECT_EQ(m2[1][0], 2);
  EXPECT_EQ(m2[1][1], 4);
}

TEST(MatrixTest, InverseTest) {
  matrix<double, 2, 2> m1{ {1, 2}, {3, 4} };
  matrix<double, 2, 2> m2 = m1.inverse();
  EXPECT_NEAR(m2[0][0], -2.0, 1e-9);
  EXPECT_NEAR(m2[0][1], 1.0, 1e-9);
  EXPECT_NEAR(m2[1][0], 1.5, 1e-9);
  EXPECT_NEAR(m2[1][1], -0.5, 1e-9);
}