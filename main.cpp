#include <iostream>

void output(const int** mtx);

void rm(int** mtx);

int** make(int rows, int cols) {

}

int main() {
  int rows = 0;
  int cols = 0;
  std::cin >> rows >> cols;
  if (std::cin.fail()) {
    return 1;
  }
  int** mtx = nullptr;
  mtx = make(rows, cols);
  output(mtx);
  rm(mtx);
}
