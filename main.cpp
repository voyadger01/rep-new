#include <iostream>

void output(const int* const* mtx);
void rm(int** mtx, int r);
int** make(int r, int c);

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

int main() {
  int rows = 0;
  int cols = 0;
  std::cin >> rows >> cols;
  if (std::cin.fail()) {
    return 1;
  }
  int** mtx = nullptr;
  try {
    mtx = make(rows, cols);
    output(mtx);
    rm(mtx, rows);
  } catch (const std::bad_alloc &) {
    rm(mtx, rows);
    return 2;
  }
}
