#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(S21TestOperatorSumSubMul, OperatorSum) {
  S21Matrix matrix_one;
  S21Matrix matrix_two;
  S21Matrix matrix_expected;

  double values_one[3][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix_one.SetMatrixValues((double *)values_one);
  double values_two[3][3]{{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  matrix_two.SetMatrixValues((double *)values_two);
  double values_expected[3][3]{{10, 10, 10}, {10, 10, 10}, {10, 10, 10}};
  matrix_expected.SetMatrixValues((double *)values_expected);

  S21Matrix matrix_three = matrix_one + matrix_two;
  ASSERT_TRUE(matrix_three == matrix_expected);
}

TEST(S21TestOperatorSumSubMul, OperatorSumException) {
  S21Matrix matrix_one;
  S21Matrix matrix_two(2, 2);

  try {
    S21Matrix matrix_three = matrix_one + matrix_two;
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(std::string(e.what()), "Different dimensions of matrices");
  } catch (const std::exception &e) {
    FAIL() << "Expected std::invalid_argument, but got: " << e.what();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument, but got a different exception";
  }
}

TEST(S21TestOperatorSumSubMul, OperatorSumEq) {
  S21Matrix matrix_one;
  S21Matrix matrix_two;
  S21Matrix matrix_expected;

  double values_one[3][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix_one.SetMatrixValues((double *)values_one);
  double values_two[3][3]{{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  matrix_two.SetMatrixValues((double *)values_two);
  double values_expected[3][3]{{10, 10, 10}, {10, 10, 10}, {10, 10, 10}};
  matrix_expected.SetMatrixValues((double *)values_expected);

  matrix_one += matrix_two;
  ASSERT_TRUE(matrix_one == matrix_expected);
}

TEST(S21TestOperatorSumSubMul, OperatorSumEqException) {
  S21Matrix matrix_one;
  S21Matrix matrix_two(2, 2);

  try {
    matrix_one += matrix_two;
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(std::string(e.what()), "Different dimensions of matrices");
  } catch (const std::exception &e) {
    FAIL() << "Expected std::invalid_argument, but got: " << e.what();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument, but got a different exception";
  }
}

TEST(S21TestOperatorSumSubMul, OperatorSub) {
  S21Matrix matrix_one;
  S21Matrix matrix_two;
  S21Matrix matrix_three;
  S21Matrix matrix_expected;

  double values_one[3][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix_one.SetMatrixValues((double *)values_one);
  double values_two[3][3]{{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  matrix_two.SetMatrixValues((double *)values_two);
  double values_expected[3][3]{{-8, -6, -4}, {-2, 0, 2}, {4, 6, 8}};
  matrix_expected.SetMatrixValues((double *)values_expected);

  matrix_three = matrix_one - matrix_two;
  ASSERT_TRUE(matrix_three == matrix_expected);
}

TEST(S21TestOperatorSumSubMul, OperatorSubException) {
  S21Matrix matrix_one;
  S21Matrix matrix_two(2, 2);

  try {
    S21Matrix matrix_three = matrix_one - matrix_two;
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(std::string(e.what()), "Different dimensions of matrices");
  } catch (const std::exception &e) {
    FAIL() << "Expected std::invalid_argument, but got: " << e.what();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument, but got a different exception";
  }
}

TEST(S21TestOperatorSumSubMul, OperatorSubEq) {
  S21Matrix matrix_one;
  S21Matrix matrix_two;
  S21Matrix matrix_expected;

  double values_one[3][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix_one.SetMatrixValues((double *)values_one);
  double values_two[3][3]{{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  matrix_two.SetMatrixValues((double *)values_two);
  double values_expected[3][3]{{-8, -6, -4}, {-2, 0, 2}, {4, 6, 8}};
  matrix_expected.SetMatrixValues((double *)values_expected);

  matrix_one -= matrix_two;
  ASSERT_TRUE(matrix_one == matrix_expected);
}

TEST(S21TestOperatorSumSubMul, OperatorSubEqException) {
  S21Matrix matrix_one;
  S21Matrix matrix_two(2, 2);

  try {
    matrix_one -= matrix_two;
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(std::string(e.what()), "Different dimensions of matrices");
  } catch (const std::exception &e) {
    FAIL() << "Expected std::invalid_argument, but got: " << e.what();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument, but got a different exception";
  }
}

TEST(S21TestOperatorSumSubMul, OperatorMulMatrix) {
  S21Matrix matrix_one;
  S21Matrix matrix_two;
  S21Matrix matrix_expected;

  double values_one[3][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix_one.SetMatrixValues((double *)values_one);
  double values_two[3][3]{{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  matrix_two.SetMatrixValues((double *)values_two);
  double values_expected[3][3]{{30, 24, 18}, {84, 69, 54}, {138, 114, 90}};
  matrix_expected.SetMatrixValues((double *)values_expected);

  S21Matrix matrix_three = matrix_one * matrix_two;
  ASSERT_TRUE(matrix_three == matrix_expected);
}

TEST(S21TestOperatorSumSubMul, OperatorMulMatrixException) {
  S21Matrix matrix_one(3, 2);
  S21Matrix matrix_two;

  try {
    S21Matrix matrix_three = matrix_one * matrix_two;
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(
        std::string(e.what()),
        "Number of columns of first matrix must be equal to number of rows of "
        "second matrix");
  } catch (const std::exception &e) {
    FAIL() << "Expected std::invalid_argument, but got: " << e.what();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument, but got a different exception";
  }
}

TEST(S21TestOperatorSumSubMul, OperatorMulEqMatrix) {
  S21Matrix matrix_one;
  S21Matrix matrix_two;
  S21Matrix matrix_expected;

  double values_one[3][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix_one.SetMatrixValues((double *)values_one);
  double values_two[3][3]{{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  matrix_two.SetMatrixValues((double *)values_two);
  double values_expected[3][3]{{30, 24, 18}, {84, 69, 54}, {138, 114, 90}};
  matrix_expected.SetMatrixValues((double *)values_expected);

  matrix_one *= matrix_two;
  ASSERT_TRUE(matrix_one == matrix_expected);
}

TEST(S21TestOperatorSumSubMul, OperatorMulEqMatrixException) {
  S21Matrix matrix_one(3, 2);
  S21Matrix matrix_two;

  try {
    matrix_one *= matrix_two;
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(
        std::string(e.what()),
        "Number of columns of first matrix must be equal to number of rows of "
        "second matrix");
  } catch (const std::exception &e) {
    FAIL() << "Expected std::invalid_argument, but got: " << e.what();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument, but got a different exception";
  }
}

TEST(S21TestOperatorSumSubMul, OperatorMulNumber) {
  S21Matrix matrix_one;
  S21Matrix matrix_expected;

  double values_one[3][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix_one.SetMatrixValues((double *)values_one);
  double values_expected[3][3]{{5, 10, 15}, {20, 25, 30}, {35, 40, 45}};
  matrix_expected.SetMatrixValues((double *)values_expected);

  S21Matrix matrix_two = matrix_one * 5;
  ASSERT_TRUE(matrix_two == matrix_expected);
}

TEST(S21TestOperatorSumSubMul, OperatorMulEqNumber) {
  S21Matrix matrix;
  S21Matrix matrix_expected;

  double values_one[3][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  matrix.SetMatrixValues((double *)values_one);
  double values_expected[3][3]{{5, 10, 15}, {20, 25, 30}, {35, 40, 45}};
  matrix_expected.SetMatrixValues((double *)values_expected);

  matrix *= 5;
  ASSERT_TRUE(matrix == matrix_expected);
}