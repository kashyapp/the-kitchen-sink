#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector< vector<char> > matrix_t;

int search_x[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int search_y[] = {-1,  0,  1, -1, 1, -1, 0, 1};

bool search(matrix_t &matrix, int x, int y, string needle, int start_index, bool scan) {
  int x_max = matrix.size() - 1;
  int y_max = matrix[0].size() - 1;

  if (x < 0 || x > x_max) return false;
  if (y < 0 || y > y_max) return false;

  if (needle.size() == start_index) {
    return true;
  }

  if (matrix[x][y] == needle[start_index]) {
    int original_char = matrix[x][y];
    matrix[x][y] = '.';
    for (int i = 0; i < 8; ++i) {
      bool found = search(matrix, x + search_x[i], y + search_y[i], needle, start_index + 1, false);
      if (found) return true;
    }
    matrix[x][y] = original_char;
  }

  if (scan) {
    if (y < y_max) {
      return search(matrix, x, y + 1, needle, start_index, true);
    } else if (x < x_max) {
      return search(matrix, x + 1, 0, needle, start_index, true);
    }
  }

  return false;
}

int main() {
  int m, n;
  cin >> m >> n;
  
  matrix_t matrix;

  for (int i = 0; i < m; ++i) {
    vector<char> row;
    matrix.push_back(row);
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      matrix[i].push_back(c);
    }
  }

  string needle;
  cin >> needle;

  if (search(matrix, 0, 0, needle, 0, true)) {
    cout << "TRUE" << endl;
  } else {
    cout << "FALSE" << endl;
  }

  return 0;
}
