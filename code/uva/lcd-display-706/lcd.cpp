#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;

char digits[][10] = {
  {'-', '|', '|', ' ', '|', '|', '-'},
  {' ', ' ', '|', ' ', ' ', '|', ' '},
  {'-', ' ', '|', '-', '|', ' ', '-'},
  {'-', ' ', '|', '-', ' ', '|', '-'},
  {' ', '|', '|', '-', ' ', '|', ' '},
  {'-', '|', ' ', '-', ' ', '|', '-'},
  {'-', '|', ' ', '-', '|', '|', '-'},
  {'-', ' ', '|', ' ', ' ', '|', ' '},
  {'-', '|', '|', '-', '|', '|', '-'},
  {'-', '|', '|', '-', ' ', '|', '-'},
  {' ', ' ', ' ', '-', ' ', ' ', ' '},
};

void r(int rid, char *number, int scale) {
  int len = strlen(number);
  for(int ni=0; ni < len; ni++) {
    if (ni > 0) putchar(' ');

    int digit = number[ni] - '0';

    putchar(' ');
    for(int i=0; i < scale; i++) {
      putchar(digits[digit][rid]);
    }
    putchar(' ');
  }
  putchar('\n');
}

void c(int cid, char *number, int scale) {
  int len = strlen(number);
  for(int i=0; i < scale; i++) {
    for(int ni=0; ni < len; ni++) {
      if (ni > 0) putchar(' ');

      int digit = number[ni] - '0';

      putchar(digits[digit][cid]);
      for(int j=0; j < scale; j++) {
        putchar(' ');
      }
      putchar(digits[digit][cid+1]);
    }
    putchar('\n');
  }
}

void lcd(char *number, int scale) {
  r(0, number, scale);
  c(1, number, scale);
  r(3, number, scale);
  c(4, number, scale);
  r(6, number, scale);
  putchar('\n');
}



int main() {
  int scale;
  char number[100];

  while(cin >> scale >> number) {
    if (scale == 0) break;
    lcd(number, scale);
  }

  return 0;
}
