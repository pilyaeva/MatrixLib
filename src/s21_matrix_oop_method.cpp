#include "s21_matrix_oop.h"

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument("Rows or columns can't be less than 0");
  }

  rows_ = rows;
  cols_ = cols;

  AllocateMatrix();
  SetMatrixValuesZero();
}

S21Matrix::S21Matrix() : S21Matrix(3, 3) {}

void S21Matrix::AllocateMatrix() {
  matrix_ = new double*[rows_];

  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
}

S21Matrix::~S21Matrix() { DeallocateMatrix(); }

void S21Matrix::DeallocateMatrix() {
  for (int i = 0; i < rows_; i++) {
    if (matrix_[i] != nullptr) {
      delete[] matrix_[i];
    }
  }

  if (matrix_ != nullptr) {
    delete[] matrix_;
  }
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.rows_;

  AllocateMatrix();
  SetMatrixSize(other.rows_, other.cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;

  matrix_ = other.matrix_;

  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

void S21Matrix::SetRows(int rows) { SetMatrixSize(rows, cols_); }

void S21Matrix::SetCols(int cols) { SetMatrixSize(rows_, cols); }

void S21Matrix::SetMatrixSize(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument(
        "Columns or rows cannot be equal to or less than 0");
  }

  if (rows == rows_ && cols == cols_) {
    return;
  }

  S21Matrix temp_matrix(rows, cols);

  int temp_rows = std::min(rows, rows_);
  int temp_cols = std::min(cols, cols_);

  for (int i = 0; i < temp_rows; i++) {
    for (int j = 0; j < temp_cols; j++) {
      temp_matrix.matrix_[i][j] = matrix_[i][j];
    }
  }

  DeallocateMatrix();
  rows_ = rows;
  cols_ = cols;
  AllocateMatrix();

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = temp_matrix.matrix_[i][j];
    }
  }
}

void S21Matrix::SetMatrixValues(double* values) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = values[(i * cols_) + j];
    }
  }
}

void S21Matrix::SetMatrixValuesZero() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}

//-------------

// void S21Matrix::print_matrix() {
//   printf("\n");
//   for (int i = 0; i < rows_; i++) {
//     for (int j = 0; j < cols_; j++) {
//       printf("%f ", matrix_[i][j]);
//     }
//     printf("\n");
//   }
// }
