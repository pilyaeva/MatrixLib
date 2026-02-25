#include "s21_matrix_oop.h"

int NearlyEqual(double a, double b, double epsilon) {
  return fabs(a - b) < epsilon;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }

  bool res = true;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (!NearlyEqual(matrix_[i][j], other.matrix_[i][j], 1e-7)) {
        res = false;
        if (!res) break;
      }
    }
  }
  return res;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Different dimensions of matrices");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Different dimensions of matrices");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] * num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "Number of columns of first matrix must be equal to number of rows of "
        "second matrix");
  }

  S21Matrix temp_matrix(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      temp_matrix.matrix_[i][j] = matrix_[i][j];
    }
  }
  SetMatrixSize(rows_, other.cols_);

  for (int i = 0; i < temp_matrix.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      matrix_[i][j] = 0;
      for (int k = 0; k < temp_matrix.cols_; k++) {
        matrix_[i][j] += temp_matrix.matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix temp_matrix(cols_, rows_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      temp_matrix.matrix_[j][i] = matrix_[i][j];
    }
  }

  return temp_matrix;
}

S21Matrix S21Matrix::CalculateMinor(int exclude_row, int exclude_cols) const {
  int m = 0;

  S21Matrix temp_matrix(rows_ - 1, cols_ - 1);

  for (int i = 0; i < rows_; i++) {
    if (i == exclude_row) {
      continue;
    }
    int n = 0;
    for (int j = 0; j < cols_; j++) {
      if (j == exclude_cols) {
        continue;
      }
      temp_matrix.matrix_[m][n] = matrix_[i][j];
      n++;
    }
    m++;
  }

  return temp_matrix;
}

double S21Matrix::Determinant() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Matrix must be square");
  }

  double res;

  if (rows_ == 1) {
    res = matrix_[0][0];
  } else if (rows_ == 2) {
    res = (matrix_[0][0] * matrix_[1][1]) - (matrix_[0][1] * matrix_[1][0]);
  } else if (rows_ == 3) {
    res = (matrix_[0][0] * matrix_[1][1] * matrix_[2][2]) +
          (matrix_[0][1] * matrix_[1][2] * matrix_[2][0]) +
          (matrix_[0][2] * matrix_[1][0] * matrix_[2][1]) -
          (matrix_[0][2] * matrix_[1][1] * matrix_[2][0]) -
          (matrix_[1][2] * matrix_[2][1] * matrix_[0][0]) -
          (matrix_[2][2] * matrix_[0][1] * matrix_[1][0]);
  } else {
    S21Matrix temp_matrix;

    res = 0;

    for (int i = 0; i < rows_; i++) {
      S21Matrix temp_matrix = CalculateMinor(i, 0);
      double temp_result = temp_matrix.Determinant();

      int value = 1;
      if (i % 2 == 0) {
        value = 1;
      } else {
        value = -1;
      }

      res += matrix_[i][0] * temp_result * value;
    }
  }
  return res;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Matrix must be square");
  }

  S21Matrix resultMatrix(rows_, cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix temp_matrix = CalculateMinor(i, j);

      double tempResult = temp_matrix.Determinant();

      resultMatrix.matrix_[i][j] = tempResult * pow(-1, i + j);
    }
  }

  return resultMatrix;
}

S21Matrix S21Matrix::InverseMatrix() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Matrix must be square");
  }

  S21Matrix matrix_algebra_add = CalcComplements();
  S21Matrix matrix_transpose = matrix_algebra_add.Transpose();
  double determinant = Determinant();

  if (determinant == 0) {
    throw std::invalid_argument("Determinant of matrix must not be 0");
  }

  matrix_transpose.MulNumber(1 / determinant);

  return matrix_transpose;
}