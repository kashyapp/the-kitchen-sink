#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

typedef vector< vector<bool> > maze_t;

struct cell {
    int col;
    int row;

    cell() { cell(0,0); }
    cell(int _x, int _y) : col(_x), row(_y){}

    bool operator==(const cell& other) {
        return col == other.col && row == other.row;
    }

    bool operator<(const cell &right) const {
        if (col == right.col) return row < right.row;
        return col < right.col;
    }
};

ostream& operator<<(ostream &os, cell &c) {
    os << "(" << c.row << "," << c.col << ")";
    return os;
}

istream& operator>>(istream &is, cell &c) {
    is >> c.row >> c.col;
    return is;
}

maze_t& operator-=(maze_t &maze, const cell &c) {
    maze[c.row][c.col] = 1;
    return maze;
}

void add_neighbour(const maze_t &maze, vector<cell> &cells, int col, int row) {
    if (maze[row][col] == 0) {
        cells.push_back(cell(col,row));
    }
}

vector<cell> neighbours(const maze_t &maze, const cell &c) {
    int m = maze.size();
    int n = maze[0].size();

    vector<cell> cells;
    if (c.col > 0)   add_neighbour(maze, cells, c.col-1, c.row);
    if (c.row > 0)   add_neighbour(maze, cells, c.col, c.row-1);
    if (c.col+1 < n) add_neighbour(maze, cells, c.col+1, c.row);
    if (c.row+1 < m) add_neighbour(maze, cells, c.col, c.row+1);

    return cells;
}

void print_path(map<cell, cell> &parents, cell end) {
    map<cell, cell>::iterator pi = parents.find(end);
    if (pi != parents.end()) {
        print_path(parents, pi->second);
    }
    cout << end << ", ";
}

bool solve(maze_t &maze, const cell &start, const cell &end) {
    map<cell, cell> parents;
    queue<cell> boundary;

    boundary.push(start);
    maze -= start;

    do {
        cell next = boundary.front(); boundary.pop();
        if (next == end) {
            print_path(parents, end);
            return true;
        }
        const vector<cell> &cells = neighbours(maze, next);
        //cerr << endl << next << endl;
        for (int i = 0; i < cells.size(); ++i) {
            cell c = cells[i];
            //cerr << "\t" << c;
            parents[c] = next;
            boundary.push(c);
            maze -= c;
        }
    } while (!boundary.empty());

    return false;
}

int main() {
    int runs;
    cin >> runs;

    while(runs--) {
        int m, n;
        cin >> m >> n;

        cell start, end;
        cin >> start >> end;

        maze_t maze(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bool b;
                cin >> b;
                maze[i][j] = b;
            }
        }

        cout << solve(maze, start, end) << endl;
    }

    return 0;
}
