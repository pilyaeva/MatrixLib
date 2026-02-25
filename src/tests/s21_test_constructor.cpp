#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(S21TestConstructor, ConstructorException) {
  try {
    S21Matrix testMatrix(-1, 3);
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(std::string(e.what()), "Rows or columns can't be less than 0");
  } catch (const std::exception &e) {
    FAIL() << "Expected std::invalid_argument, but got: " << e.what();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument, but got a different exception";
  }
}

TEST(S21TestConstructor, ConstructorCopy) {
  S21Matrix matrix_one(1, 2);

  double values[1][2]{{1, 2}};
  matrix_one.SetMatrixValues((double *)values);

  S21Matrix matrix_two(matrix_one);
  ASSERT_TRUE(matrix_one == matrix_two);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpessimizing-move"
S21Matrix CreateMatrixForMovement() {
  S21Matrix matrix_one(1, 2);

  double values[1][2]{{1, 2}};
  matrix_one.SetMatrixValues((double *)values);

  return std::move(matrix_one);
}
#pragma GCC diagnostic pop

TEST(S21TestConstructor, ConstructorMove) {
  S21Matrix matrix_expected(1, 2);
  double values_expected[1][2]{{1, 2}};
  matrix_expected.SetMatrixValues((double *)values_expected);

  S21Matrix matrix = CreateMatrixForMovement();
  ASSERT_TRUE(matrix == matrix_expected);
}