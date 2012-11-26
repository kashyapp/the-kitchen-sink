#include <vector>
#include <cctype>
#include <iostream>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
  char s1[101], s2[101];

  char *current = &s1[0];
  char *longest = &s2[0];

  int llong = 0;

  char c;
  int i = 0;
  while((c = getchar()) != EOF) {
    if (isalpha(c) || c=='-') {
      current[i++] = c;
      if (strncmp("E-N-D", current, 5) == 0) break;
    } else {
      if(i > llong) {
        current[i+1] = '\0';
        swap(current, longest);
        llong = i;
      }
      i = 0;
    }
  }

  while(*longest != '\0') {
    putchar(tolower(*longest++));
  }
  putchar('\n');

  return 0;
}
