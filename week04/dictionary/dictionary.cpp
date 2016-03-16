#include "dictionary.hpp"

Dictionary::Dictionary() {
  size = 0;
}

void Dictionary::add(const char *a, const char *b) {
  data[size++].set(a,b);
}

int Dictionary::search(const char*a) {
  for(int i = 0; i < size; ++i)
    if (strcmp(a, data[i].first) == 0)
      return i;

  return -1;
}

void Dictionary::remove(const char*a) {
  int i = search(a);
  if (i < 0)
    return;
  // изтриване чрез изместване (необходими са (size - i - 1) на брой операции)
  // --size;
  // for(;i < size; ++i)
  //   data[i] = data[i+1];

  // ако реда на елементите не ни интересува можем да запълним празното място
  // с последния елемент от масива | a,b,c,d | remove(a) | d,b,c
  --size;
  data[i] = data[size];
  // така извършваме 1 операция
}

// сигурен съм, че тук ще има много въпроси :D :D
// питайте!!!
void Dictionary::translate(const char *in, char* out) {
  const char* start = in;
  const char* end = in;

  while (*start != '\0') {
    if (!isalpha(*end)) {
      int len = end - start; // size_t

      char* word = new char[len + 1];
      strncpy(word, start, len);
      word[len] = '\0';
      int index = search(word);

      if (index >= 0) // ако думата може да се преведе...
        strcat(out, data[index].second); // strcat слепя/конкатенира два низа
      else
        strcat(out, word);

      delete [] word;

      // докато end не сочи към буква и не е стигнало края на подадения низ
      // го конкатенирай с текущия out и мести с едно напред
      while (!isalpha(*end) && *end != '\0')
        strncat(out, end++, 1);

      start = end;
    } else {
      ++end;
    }
  }
}
