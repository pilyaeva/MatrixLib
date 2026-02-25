#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(S21TestSet, InitializingMatrixOperator) {
  S21Matrix matrix;
  S21Matrix matrix_expected;
  double values[3][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix_expected.SetMatrixValues((double *)values);

  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      matrix(i, j) = i * matrix.GetCols() + j + 1;
    }
  }
  ASSERT_TRUE(matrix == matrix_expected);
}

TEST(S21TestSet, InitializingMatrixOperatorException) {
  S21Matrix matrix;
  try {
    matrix(-1, 1) = 7;
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(std::string(e.what()), "Incorrect number of rows or columns");
  } catch (const std::exception &e) {
    FAIL() << "Expected std::invalid_argument, but got: " << e.what();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument, but got a different exception";
  }
}

TEST(S21TestSet, SetRows) {
  S21Matrix matrix(1, 1);
  S21Matrix matrix_expected(2, 1);

  matrix.SetRows(2);
  ASSERT_TRUE(matrix == matrix_expected);
}

TEST(S21TestSet, SetCols) {
  S21Matrix matrix(1, 1);
  S21Matrix matrix_expected(1, 2);

  matrix.SetCols(2);
  ASSERT_TRUE(matrix == matrix_expected);
}

TEST(S21TestSet, SetMatrixSize) {
  S21Matrix matrix;
  S21Matrix matrix_expected(2, 5);

  double values[3][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix.SetMatrixValues((double *)values);
  double valuesExpected[2][5]{{1, 2, 3, 0, 0}, {4, 5, 6, 0, 0}};
  matrix_expected.SetMatrixValues((double *)valuesExpected);

  matrix.SetMatrixSize(2, 5);

  ASSERT_TRUE(matrix == matrix_expected);
}

TEST(S21TestSet, SetMatrixSizeException) {
  S21Matrix matrix;

  try {
    matrix.SetMatrixSize(-3, 5);
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(std::string(e.what()),
              "Columns or rows cannot be equal to or less than 0");
  } catch (const std::exception &e) {
    FAIL() << "Expected std::invalid_argument, but got: " << e.what();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument, but got a different exception";
  }
}