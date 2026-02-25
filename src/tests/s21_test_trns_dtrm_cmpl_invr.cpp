#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(S21TestTransDetermComplInver, Transpose) {
  S21Matrix matrix(3, 2);
  S21Matrix matrix_expected(2, 3);

  double values[3][2]{{1, 2}, {3, 4}, {5, 6}};
  matrix.SetMatrixValues((double *)values);
  double values_expected[2][3]{{1, 3, 5}, {2, 4, 6}};
  matrix_expected.SetMatrixValues((double *)values_expected);

  S21Matrix matrixTranspose = matrix.Transpose();
  ASSERT_TRUE(matrixTranspose == matrix_expected);
}

TEST(S21TestTransDetermComplInver, DeterminantException) {
  S21Matrix matrix_exception(3, 2);
  try {
    double res = matrix_exception.Determinant();
    (void)res;
    FAIL() << "Expected std::invalid_argument";
    ASSERT_TRUE(res);
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(std::string(e.what()), "Matrix must be square");
  } catch (const std::exception &e) {
    FAIL() << "Expected std::invalid_argument, but got: " << e.what();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument, but got a different exception";
  }
}

TEST(S21TestTransDetermComplInver, Determinant1) {
  S21Matrix matrix;
  double values[3][3]{{1, 2, 10}, {3, 4, 20}, {5, 6, 3}};
  matrix.SetMatrixValues((double *)values);
  double res = matrix.Determinant();
  ASSERT_EQ(res, (double)54);
}

TEST(S21TestTransDetermComplInver, Determinant2) {
  S21Matrix matrix(1, 1);
  double values[1][1]{{-5}};
  matrix.SetMatrixValues((double *)values);
  double res = matrix.Determinant();
  ASSERT_EQ(res, (double)-5);
}

TEST(S21TestTransDetermComplInver, Determinant3) {
  S21Matrix matrix(2, 2);
  double values[2][2]{{-5, 5}, {2, 3}};
  matrix.SetMatrixValues((double *)values);
  double res = matrix.Determinant();
  ASSERT_EQ(res, (double)-25);
}

TEST(S21TestTransDetermComplInver, Determinant4) {
  S21Matrix matrix(5, 5);
  double values[5][5]{{-1, 2, 3, 4, -5},
                      {10, -9, 8, -7, 6},
                      {11, 12, -13, 14, 15},
                      {20, -19, 18, -17, 16},
                      {-21, 22, 23, 24, -25}};
  matrix.SetMatrixValues((double *)values);
  double res = matrix.Determinant();
  ASSERT_EQ(res, (double)0);
}

TEST(S21TestTransDetermComplInver, CalcComplements) {
  S21Matrix matrix;
  S21Matrix matrix_expected;

  double values[3][3]{{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  matrix.SetMatrixValues((double *)values);
  double values_expected[3][3]{{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
  matrix_expected.SetMatrixValues((double *)values_expected);

  S21Matrix matrix_actual = matrix.CalcComplements();
  ASSERT_TRUE(matrix_actual == matrix_expected);
}

TEST(S21TestTransDetermComplInver, CalcComplementsException) {
  S21Matrix matrix(3, 5);

  try {
    S21Matrix matrix_exception = matrix.CalcComplements();
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(std::string(e.what()), "Matrix must be square");
  } catch (const std::exception &e) {
    FAIL() << "Expected std::invalid_argument, but got: " << e.what();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument, but got a different exception";
  }
}

TEST(S21TestTransDetermComplInver, InverseMatrix) {
  S21Matrix matrix;
  S21Matrix matrix_expected;

  double values[3][3]{{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  matrix.SetMatrixValues((double *)values);

  double values_expected[3][3]{{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
  matrix_expected.SetMatrixValues((double *)values_expected);

  S21Matrix matrix_actual = matrix.InverseMatrix();
  ASSERT_TRUE(matrix_actual == matrix_expected);
}

TEST(S21TestTransDetermComplInver, InverseMatrixExceptionZeroDeterminant) {
  S21Matrix matrix_zero_determinant;
  double values_zero_determinant[3][3]{{1, 2, 3}, {4, 5, 6}, {2, 4, 6}};
  matrix_zero_determinant.SetMatrixValues((double *)values_zero_determinant);

  try {
    S21Matrix matrix_exception_zero = matrix_zero_determinant.InverseMatrix();
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(std::string(e.what()), "Determinant of matrix must not be 0");
  } catch (const std::exception &e) {
    FAIL() << "Expected std::invalid_argument, but got: " << e.what();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument, but got a different exception";
  }
}

TEST(S21TestTransDetermComplInver, InverseMatrixExceptionNotSquare) {
  S21Matrix matrix_not_square(3, 4);

  try {
    S21Matrix matrix_exception_square = matrix_not_square.InverseMatrix();
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(std::string(e.what()), "Matrix must be square");
  } catch (const std::exception &e) {
    FAIL() << "Expected std::invalid_argument, but got: " << e.what();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument, but got a different exception";
  }
}