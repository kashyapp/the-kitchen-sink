#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

#define UNSET 0
#define LEFT 1
#define UP 2

int minToll_(int **grid, int **pathgrid, int i, int j) {
    int toll = INT_MAX;
    int path = UNSET;

    if (pathgrid[i][j] != UNSET) {
        path = pathgrid[i][j];
        toll = grid[i][j];
        //return grid[i][j];
    } else {

        if (i > 0) {
            int itoll = minToll_(grid, pathgrid, i-1, j);
            if (itoll < toll) {
                toll = itoll;
                path = UP;
            }
            
        }
        if (j > 0) {
            int jtoll = minToll_(grid, pathgrid, i, j-1);
            if (jtoll < toll) {
                toll = jtoll;
                path = LEFT;
            }
        }

        toll += grid[i][j];
        grid[i][j] = toll;

        pathgrid[i][j] = path;
    }

    cerr << i << ", " << j << " : " << path << " " << toll << endl;
    return toll;
}

void print(int **pathgrid, int i, int j) {
    int **p = pathgrid;
    while (i != 0 || j != 0) {
        cout << i << " " << j << endl;
        if (LEFT == p[i][j]) {
            j -= 1;
        } else {
            i -= 1;
        }
    }
}

int minToll(int *grid, int m, int n) {
    int **grid2 = new int*[m];
    int **pathgrid = new int*[m];
    for (int i= 0; i < m; ++i) {
        grid2[i] = &grid[n*i];
        pathgrid[i] = new int[n];
        memset(pathgrid[i], UNSET, n * sizeof(int));
    }
    pathgrid[0][0] = LEFT;

    int toll = minToll_(grid2, pathgrid, m-1, n-1);
    print(pathgrid, m-1, n-1);

    return toll;
}

int main() {
    int grid[] = {
        0, 3, 5, 3,
        2, 1, 4, 2,
        5, 2, 9, 7,
        3, 1, 1, 0
    };

    cout << minToll(grid, 4, 4) << endl;

    return 0;
}
