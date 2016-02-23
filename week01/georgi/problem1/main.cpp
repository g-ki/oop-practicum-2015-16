#include <iostream>
#include <string>
using namespace std;

int int_size(int n) {
  int i = 1;
  while (n /= 10)
    ++i;
  return i;
}

void int_to_array(int n, int* arr, int size) {
  while (size--) {
    arr[size] = n % 10;
    n /= 10;
  }
}

char* encode(char* text, int key) {
  int key_size = int_size(key);
  int key_array[10]; // int key_array[key_size]; //Visual C++  expected constant expression
  int_to_array(key, key_array, key_size);

  for (int i = 0; text[i] != '\0'; ++i)
    text[i] += key_array[i % key_size];

  return text;
}

char* decode(char* text, int key) {
  int key_size = int_size(key);
  int key_array[10]; // int key_array[key_size];
  int_to_array(key, key_array, key_size);

  for(int i = 0; text[i] != '\0'; ++i)
    text[i] -= key_array[i % key_size];

  return text;
}


// TESTS

bool int_size_test() {
  int a = 123;
  int a_size = int_size(a);
  cout << a << " has size " << a_size << endl;

  return a_size == 3;
}

bool int_to_array_test() {
  int a = 1234;
  int a_size = int_size(a);
  int a_array[10]; // int a_array[a_size];
  int_to_array(a, a_array, a_size);

  int test[] = {1,2,3,4};

  for (int i = 0; i < a_size; ++i) {
    if (a_array[i] != test[i]) {
      cout << "mismatch: " << a_array << " != " << test[i] << endl;
      return false;
    }
  }

  return true;
}

bool encode_decode_test() {
  char t[] = "Secret message!";
  int k = 473943211;
  char t_encode[strlen(t)];
  strcpy(t_encode, t);

  encode(t_encode, k);
  if (strcmp(t, t_encode) == 0) return false;

  decode(t_encode, k);
  if (strcmp(t, t_encode) == 0) return true;

  return false;
}

// MENU

void menu() {
  int key;
  do {
    cout << "Enter the key: ";
    cin >> key;
  } while(int_size(key) > 10 || key < 0);

  char text[50];
  cout << "Enter the text: ";
  cin.ignore();
  cin.getline(text, 50);
  cout << endl;
  cout << "ENCODE: " << encode(text, key) << endl << endl;
  cout << "DECODE: " << decode(text, key) << endl;
}


int main() {

  menu();

  // int_size_test();
  // int_to_array_test();
  // encode_decode_test();

  return 0;
}
