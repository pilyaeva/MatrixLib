#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(S21TestSubSumMult, SumMatrix) {
  S21Matrix matrix_one(3, 2);
  S21Matrix matrix_two(3, 2);
  S21Matrix matrix_expected(3, 2);

  double values_one[3][2]{{1, 2}, {3, 4}, {5, 6}};
  matrix_one.SetMatrixValues((double *)values_one);
  double values_two[3][2]{{3, 3}, {4, 2}, {5, 1}};
  matrix_two.SetMatrixValues((double *)values_two);
  double values_expected[3][2]{{4, 5}, {7, 6}, {10, 7}};
  matrix_expected.SetMatrixValues((double *)values_expected);

  matrix_one.SumMatrix(matrix_two);
  ASSERT_TRUE(matrix_one == matrix_expected);
}

TEST(S21TestSubSumMult, SumMatrixException) {
  S21Matrix matrix_one(3, 2);
  S21Matrix matrix_two;

  try {
    matrix_one.SumMatrix(matrix_two);
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(std::string(e.what()), "Different dimensions of matrices");
  } catch (const std::exception &e) {
    FAIL() << "Expected std::invalid_argument, but got: " << e.what();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument, but got a different exception";
  }
}

TEST(S21TestSubSumMult, SubMatrix) {
  S21Matrix matrix_one(3, 2);
  S21Matrix matrix_two(3, 2);
  S21Matrix matrix_expected(3, 2);

  double values_one[3][2]{{1, 2}, {3, 4}, {5, 6}};
  matrix_one.SetMatrixValues((double *)values_one);
  double values_two[3][2]{{3, 3}, {4, 2}, {5, 1}};
  matrix_two.SetMatrixValues((double *)values_two);
  double values_expected[3][2]{{-2, -1}, {-1, 2}, {0, 5}};
  matrix_expected.SetMatrixValues((double *)values_expected);

  matrix_one.SubMatrix(matrix_two);
  ASSERT_TRUE(matrix_one == matrix_expected);
}

TEST(S21TestSubSumMult, SubMatrixException) {
  S21Matrix matrix_one(3, 2);
  S21Matrix matrix_two;

  try {
    matrix_one.SubMatrix(matrix_two);
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(std::string(e.what()), "Different dimensions of matrices");
  } catch (...) {
    FAIL() << "Expected std::invalid_argument, but got a different exception";
  }
}

TEST(S21TestSubSumMult, MulNumber) {
  S21Matrix matrix(3, 2);
  S21Matrix matrix_expected(3, 2);

  double values_actual[3][2]{{1, 2}, {3, 4}, {5, 6}};
  matrix.SetMatrixValues((double *)values_actual);
  double values_expected[3][2]{{4, 8}, {12, 16}, {20, 24}};
  matrix_expected.SetMatrixValues((double *)values_expected);

  matrix.MulNumber(4);
  ASSERT_TRUE(matrix == matrix_expected);
}

TEST(S21TestSubSumMult, MulMatrix) {
  S21Matrix matrix_one(3, 2);
  S21Matrix matrix_two(2, 3);
  S21Matrix matrix_expected(3, 3);

  double values_one[3][2]{{1, 2}, {3, 4}, {5, 6}};
  matrix_one.SetMatrixValues((double *)values_one);
  double values_two[2][3]{{6, 5, 4}, {3, 2, 1}};
  matrix_two.SetMatrixValues((double *)values_two);
  double values_expected[3][3]{{12, 9, 6}, {30, 23, 16}, {48, 37, 26}};
  matrix_expected.SetMatrixValues((double *)values_expected);

  matrix_one.MulMatrix(matrix_two);
  ASSERT_TRUE(matrix_one == matrix_expected);
}

TEST(S21TestSubSumMult, MulMatrixException) {
  S21Matrix matrix_one(4, 3);
  S21Matrix matrix_two(4, 4);

  try {
    matrix_one.MulMatrix(matrix_two);
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(std::string(e.what()),
              "Number of columns of first matrix must be equal to number of "
              "rows of second matrix");
  } catch (const std::exception &e) {
    FAIL() << "Expected std::invalid_argument, but got: " << e.what();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument, but got a different exception";
  }
}