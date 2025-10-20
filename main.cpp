#include <iostream>

void clearArray(int**m, size_t rows);

int** create(size_t rows, size_t cols) {
  int** result = new int*[rows];
  size_t i = 0;
  try{
    for (; i < rows; ++i) {
      result[i] = new int[cols];
    }
  }
  catch (...) {
    clearArray(result, i);
    throw;
  }

  return result;
}



void clearArray(int** m, size_t rows){
  for (size_t i = 0; i < rows; ++i) {
    delete[] m[i];
  }
  delete[] m;
}



void input(int**  m, size_t rows, size_t cols){
  for (size_t i = 0; i < rows && (std::cin); ++i){
    for (size_t j = 0; j < cols && (std::cin); ++j){
      std::cin >> m[i][j];
    }  
  }
}


void output(const int * const * m, size_t rows, size_t cols){
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols-1; ++j) {
      std::cout << m[i][j] << " ";
    }
    std::cout << m[i][cols-1] << "\n";
  }
}




int ** convert(const int * t, size_t n, const size_t * lns, size_t rows) {

  size_t count = 0;

  if ((rows==0) || (t==nullptr) || (lns==nullptr)) {
    return nullptr;
  }

  for (size_t i = 0; i < rows; ++i) {
    count += lns[i];
  }

  if (count != n) {
    return nullptr;
  }

  int ** result = new int*[rows];
  size_t i = 0;
  try {
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < lns[i]; ++j) {
        result[i][j] = ((i > 0) ? t[i*lns[i-1]+j] : t[j]);
      }
    }
    return result;
  }
  catch (...) {
    clearArray(result, i);
    throw;
  }
}


int main()
{

  size_t rows = 0, cols = 0;
  std::cin >> rows >> cols;
  if (!std::cin) {
    return 1;
  }

  int** m = create(rows, cols);
  
  input(m, rows, cols);

  if (!std::cin){
    clearArray(m, rows);
    return 1;
  }

  output(m, rows, cols);

  clearArray(m, rows);
  std::cout << "\n";
}
