#include <iostream>


int** create(size_t rows, size_t cols) {
  int** result = new int*[rows];
  size_t i = 0;
  try{
    for (; i < rows; ++i) {
      result[i] = new int[cols];
    }
  }
  catch (...) {
    remove(result, i);
    return nullptr;
    throw;
  }

  return result;
}



void remove(int** m, size_t rows){
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
    for(size_t j = 0; j < cols-1; ++j) {
      std::cout << m[i][j] << " ";
    }
    std::cout << m[i][cols-1] << "\n";
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
    remove(m, rows, cols);
    return 1;
  }

  output(m, rows, cols);

  remove(m, rows);
  std::cout << "\n";
}
