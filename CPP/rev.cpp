#include <iostream>
#include <string.h>

using namespace std;
void str_rev(char *str, int len) {

  if (str == nullptr || len < 2) {
    return;
  }

  char *start = str;
  char *end = str + len - 1;

  while (start < end) {
    if (start != nullptr && end != nullptr) {
      char temp = * start;
      *start = *end;
      *end = temp;
    }
    start++;
    end--;
  }
}

void reverse_words(char *sentence) {

  // Here sentence is a null-terminated string ending with char '\0'.
  if (sentence == nullptr) {
    return;
  }

  // To reverse all words in the string, we will first reverse
  // the string. Now all the words are in the desired location, but
  // in reverse order: "Hello World" -> "dlroW olleH".

  int len = strlen(sentence);
  str_rev(sentence, len);

  // Now, let's iterate the sentence and reverse each word in place.
  // "dlroW olleH" -> "World Hello"

  char *start = sentence;
  char *end;
  while (true) {
    // find the  start index of a word while skipping spaces.
    while (start && *start == ' ') {
      ++start;
    }

    if (start == nullptr || *start == '\0') {
      break;
    }

    // find the end index of the word.
    end = start + 1;
    while (end && *end != '\0' && *end != ' ') {
      ++end;
    }

    // let's reverse the word in-place.
    if (end != nullptr) {
      str_rev(start, (end - start));
    }

    start = end;
  }
}

int main() {
  string str = "I love programming";
  char *a = const_cast<char*>(str.c_str());

  cout << a << endl;
  reverse_words(a);
  cout << a << endl;
}
