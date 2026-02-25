#ifndef __S21MATRIX_OOP_H__
#define __S21MATRIX_OOP_H__

#include <math.h>
#include <stdlib.h>

#include <algorithm>
#include <stdexcept>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  int GetRows() const { return rows_; }
  int GetCols() const { return cols_; }

  void SetRows(int rows);
  void SetCols(int cols);
  void SetMatrixSize(int rows, int cols);
  void SetMatrixValues(double* values);
  void SetMatrixValuesZero();

  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  double Determinant() const;
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  S21Matrix InverseMatrix() const;

  S21Matrix CalculateMinor(int exclude_row, int exclude_cols) const;

  S21Matrix operator=(const S21Matrix& other);
  bool operator==(const S21Matrix& other) const;
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(const double num) const;
  S21Matrix operator*=(const S21Matrix& other);
  S21Matrix operator*=(const double num);
  double& operator()(int rows, int cols);

 private:
  void AllocateMatrix();
  void DeallocateMatrix();
};

#endif