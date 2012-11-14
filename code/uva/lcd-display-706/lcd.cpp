#include <iostream>

void print(int n) {
  bool segments[10][7] = {
    {1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1},
  };

  bool *s = segments[n];
  bool canvas[1000][1000];
  int offset = 0;
  canvas[0][offset + 1] = s[0];
  canvas[1][offset + 0] = s[1];
  canvas[1][offset + 2] = s[2];
  canvas[2][offset + 1] = s[3];
  canvas[3][offset + 0] = s[4];
  canvas[3][offset + 2] = s[5];
  canvas[4][offset + 1] = s[6];
}

int main() {
    int n;
  cin >> n;



  return 0;
}
