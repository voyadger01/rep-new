#include <iostream>

void output(const int* const* mtx, int r, int c);
void rm(int** mtx, int r);
int** make(int r, int c);
void input (int** mtx, int r, int c);
int** convert (const int* t, size_t n, const size_t* lns, size_t rows);
size_t numCols(size_t* lns, size_t rows);

int main() {
  int test = 0;
  std::cin >> test;
  if (test == 1) {
    size_t n = 12;
    size_t rows  = 4;
    size_t lns[rows] {4, 2, 5, 1};
    size_t i = numCols(lns, rows);
    int t[n] {5, 5, 5, 5, 6, 6, 7, 7, 7, 7, 7, 8};
    int** mtx = convert(t, n, lns, rows);
    output(mtx, rows, i);
    rm(mtx, rows);
    return 0;
  }

  int rows = 0;
  int cols = 0;
  std::cin >> rows >> cols;
  if (std::cin.fail()) {
    return 1;
  }
  int** mtx = nullptr;
  try {
    mtx = make(rows, cols);
  } catch (const std::bad_alloc &) {
    rm(mtx, rows);
    return 2;
  }
  input(mtx, rows, cols);
  if (std::cin.fail()) {
    return 1;
  }
  output(mtx, rows, cols);
  rm(mtx, rows);
}

void rm (int** mtx, int r) {
  for (size_t i = 0; i < r; ++i){
    delete[] mtx[i];
  }
  delete[] mtx;
}

int** make(int r, int c) {
  int** mtx = new int*[r];
  for (size_t i = 0; i < r; ++i){
    try {
      mtx[i] = new int[c];
    } catch (const std::bad_alloc &) {
    rm(mtx, i);
    throw;
    }
  }
  return mtx;
}

void input (int** mtx, int r, int c) {
  for (size_t i = 0; i < r; ++i){
    for (size_t j = 0; j < c; ++j){
      std::cin >> mtx[i][j];
    }
  }
}

void output (const int* const* mtx, int r, int c) {
  for (size_t i = 0; i < r; ++i){
    for (size_t j = 0; j < c; ++j){
      std::cout << mtx[i][j] << '\t';
    }
    std::cout << '\n';
  }
}

void output (const int* const* mtx, size_t r, size_t c) {
  for (size_t i = 0; i < r; ++i){
    for (size_t j = 0; j < c; ++j){
      std::cout << mtx[i][j] << '\t';
    }
    std::cout << '\n';
  }
}

int** convert(const int* t, size_t n, const size_t* lns, size_t rows) {
    int** mtx = new int*[rows];
    size_t idx = 0;
    for (size_t i = 0; i < rows; ++i) {
        mtx[i] = new int[lns[i]];
        for (size_t j = 0; j < lns[i]; ++j) {
            mtx[i][j] = t[idx++];
        }
    }
    return mtx;
}

size_t numCols(size_t* lns, size_t rows) {
  size_t cols = 0;
  for (size_t i = 0; i < rows - 1; ++i) {
    if (lns[i+1] > lns[i]) {
      cols = lns[i+1];
    }
  }
  return cols;
}
