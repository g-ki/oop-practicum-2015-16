#include <iostream>
using namespace std;

void swap(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void sieve_array(int* arr, int size, bool left_to_right = true) {
  while (size > 1) {

    //int i = (left_to_right || size % 2 != 0) ? 1 : 0;
    int i = (left_to_right || size % 2 != 0);
    for (; i < size; i += 2)
      swap(arr[i], arr[i / 2]);

    size /= 2;
    left_to_right = !left_to_right;
  }
}

bool sieve_array_test() {

  int arr[] = {1,2,3,4,5,6,7,8,9};
  sieve_array(arr, 9);
  cout << 6 << " == " << arr[0] << endl;
  if (arr[0] != 6) return false;


  int arr1[] = {1,2,3,4,5,6};
  sieve_array(arr1, 6);
  cout << 4 << " == " << arr1[0] << endl;
  if (arr1[0] != 4) return false;

  return true;
}

void menu() {

  int n;

  do {
    cout << "Enter size of the array: ";
    cin >> n;
  } while(n < 0 || n > 100);

  int arr[n];
  for (int i = 0; i < n; ++i) {
    cout << "array[" << i << "]: ";
    cin >> arr[i];
  }

  sieve_array(arr, n);
  cout << "last: " << arr[0] << endl;
}

int main() {

  menu();
  //sieve_array_test();

  return 0;
}
