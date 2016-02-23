#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n) {

  if(n <= 1)
    return false;

  int sqrt_n = sqrt(n);
  for (int i = 2; i <= sqrt_n; ++i)
    if (n % i == 0) return false;

  return true;
}

int get_primes(int matrix[][15], int n, int* result) {
  int size = 0;

  for (int k=0; k < n; ++k)
    for (int i=0, j=k; i<n && j >= 0; ++i, --j)
      if(is_prime(matrix[i][j]))
        result[size++] = matrix[i][j];

  for (int k=1; k < n; ++k)
    for (int i=k, j=n-1; i<n && j >= 0; ++i, --j)
      if(is_prime(matrix[i][j]))
        result[size++] = matrix[i][j];

  return size;
}

int main() {
  int n;
  do {
    cout << "Enter the matrix size: ";
    cin >> n;
  } while(n < 0 || n > 15);

  int matrix[15][15];

  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      cout << "M[" << i << "][" << j << "]= ";
      cin >> matrix[i][j];
    }
  }

  int result[n*n];
  int result_size = 0;
  result_size = get_primes(matrix, 3, result);

  for (int i=0; i < result_size; ++i)
    cout << result[i] << " ";

  cout << endl;

  return 0;
}
