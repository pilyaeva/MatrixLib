#include "s21_matrix_oop.h"

double& S21Matrix::operator()(int rows, int cols) {
  if (rows < 0 || cols < 0 || rows >= rows_ || cols >= cols_) {
    throw std::invalid_argument("Incorrect number of rows or columns");
  }
  return matrix_[rows][cols];
}

S21Matrix S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    if (matrix_ != nullptr) {
      DeallocateMatrix();
    }
  }

  rows_ = other.rows_;
  cols_ = other.cols_;

  AllocateMatrix();

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }

  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  bool res = EqMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

S21Matrix S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}