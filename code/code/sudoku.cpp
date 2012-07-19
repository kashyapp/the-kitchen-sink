/**
 * matrix
 * bitset
 * cell
 *
 * parse input
 * solve
 *    prepare/prepopulate
 *    enqueue
 *    fill
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <sys/time.h>
#include <string>
#include <cctype>

using namespace std;

#define N 9
#define BLANK '.'

int counter = 0;

typedef char row_t[N];
typedef row_t* matrix_t;
void print (matrix_t matrix);

class profiler {
  public:
    profiler(string _name) : name(_name) {
      gettimeofday(&t0, NULL);
    }
    ~profiler() {
      timeval t1;
      gettimeofday(&t1, NULL);
      cerr << name << " " <<  1000000 * (t1.tv_sec - t0.tv_sec) + (t1.tv_usec - t0.tv_usec) << endl;
    }
  private:
    timeval t0;
    string name;
};

namespace sudoku {
  typedef pair<int, int> cellref_t;

  class solver {

    public:
      solver(matrix_t _matrix) {
        matrix = _matrix;
        minlen = 81;
        memset(rowsets, 0, sizeof(rowsets));
        memset(colsets, 0, sizeof(colsets));
        memset(gridsets, 0, sizeof(gridsets));
      }

      bool solve() {
        profiler p("solver::solve");
        return fill(prepare());
      }

    private:
      matrix_t matrix;
      unsigned short rowsets[N];
      unsigned short colsets[N];
      unsigned short gridsets[N/3][N/3];
      int minlen;

      void put(int i, int j, short n) {
        unsigned short b = 1U << n;

        rowsets[i] |= b;
        colsets[j] |= b;
        gridsets[i/3][j/3] |= b;
      }

      void unput(int i, int j, short n) {
        unsigned short b = ~(1U << n);

        rowsets[i] &= b;
        colsets[j] &= b;
        gridsets[i/3][j/3] &= b;
      }

      vector<cellref_t> prepare() {
        profiler p("solver::prepare");
        vector<cellref_t> emptyCells;

        for (int i = 0; i < N; ++i) {
          for (int j = 0; j < N; ++j) {
            char c = matrix[i][j];
            if (c == BLANK) {
              emptyCells.push_back(make_pair(i, j));
            } else {
              short n = c - '1';
              put(i, j, n);
            }
          }
        }

        return emptyCells;
      }

      bool fill(vector<cellref_t> emptyCells) {
        if (false)
        //if (emptyCells.size() < minlen) 
        {
          minlen = emptyCells.size();
          print(matrix);
          cout << endl;
        }

        if (emptyCells.empty()) {
          return true;
        }

        cellref_t cell = emptyCells.back(); emptyCells.pop_back();
        const int i = cell.first;
        const int j = cell.second;

        unsigned short exclusions = rowsets[i] | colsets[j] | gridsets[i/3][j/3];
        unsigned short mask = (1U << N) - 1;

        for (int n = 0; exclusions != mask && n < N; ++n, exclusions >>= 1, mask >>= 1 ) {
          ++counter;
          if ((exclusions & 1U) == 0) {
            put(i, j, n);
            matrix[i][j] = '1' + n;

            bool done = fill(emptyCells);

            if (done) {
              return done;
            } else {
              unput(i, j, n);
              matrix[i][j] = BLANK;
            }
          }
        }
        //cout << "< " << setbase(8) << exclusions << " " << mask << endl;

        return false;
      }
  };

  bool solve(matrix_t matrix) {
    profiler p("solve");
    sudoku::solver s(matrix);
    return s.solve();
  }

}

void readInput(char matrix[N][N]) {
  char c;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      do {
        cin >> c;
        cerr << c << endl;
      } while (!isdigit(c) && c != '.');
      matrix[i][j] = c;
    }
  }
}

void print (char matrix[N][N]) {
  for (int i = 0; i < N; ++i) {
    if (i && i % 3 == 0) {
      cout << "------+-------+------" << endl;
    }
    for (int j = 0; j < N; ++j) {
      if (j && j % 3 == 0) {
        cout << "| ";
      }
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  profiler p("main");
  row_t matrix[N];
  readInput(matrix);

  print(matrix); cout << endl;

  bool done = sudoku::solve(matrix);

  cout << counter << endl;

  if (done) {
    print(matrix);
  } else {
    cerr << "hasn't got a solution" << endl; 
  }

  return 0;
}
