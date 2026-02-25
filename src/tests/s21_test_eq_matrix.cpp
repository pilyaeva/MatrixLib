#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(S21EqualityMatrix, EqMatrixZero) {
  S21Matrix matrix_one;
  S21Matrix matrix_two;

  bool res = matrix_one.EqMatrix(matrix_two);
  ASSERT_TRUE(res);
}

TEST(S21EqualityMatrix, EqMatrixFalseValues) {
  S21Matrix matrix_one;
  S21Matrix matrix_two;

  double values[3][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix_two.SetMatrixValues((double *)values);

  bool res = matrix_one.EqMatrix(matrix_two);
  ASSERT_FALSE(res);
}

TEST(S21EqualityMatrix, EqMatrixFalseRowsCols) {
  S21Matrix matrix_one(2, 3);
  S21Matrix matrix_two;

  bool res = matrix_one.EqMatrix(matrix_two);
  ASSERT_FALSE(res);
}