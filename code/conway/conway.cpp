#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>

using namespace std;

typedef char **world_t;

class World {
    int M, N;
    world_t bar, bee;

    public:
    World(int m, int n, istream &in) {
        M = m;
        N = n;
        bar = (world_t)calloc(m, sizeof(char *));
        bee = (world_t)calloc(m, sizeof(char *));
        for (int i = 0; i < m; ++i) {
            bar[i] = (char *)calloc(n+1, sizeof(char));
            bee[i] = (char *)calloc(n+1, sizeof(char));

            in.getline(bar[i], n+1); 
            cout << bar[i] << endl;
        }
    }

    void print(world_t &world) {
        for (int i = 0; i < M; ++i) {
            cout << world[i];
            cout << endl;
        }
        cout << endl;
    }

    static const int neighbours[8][2];
    int count(world_t &world, int i, int j) {
        int c = 0;
        for (int t = 0; t < 8; ++t) {
            int x = i + neighbours[t][0];
            int y = j + neighbours[t][1];
            if (x == M) x = 0;
            if (x < 0) x = M - 1;
            if (y == N) y = 0;
            if (y < 0) y = N - 1;
            //cout << i << " " << j << " -> " <<  x << " " << y << endl;
            c += (world[x][y] == '.');
        }
        if (c > 0) {
            //cout << i << " " << j << " : " << c << endl; 
        }
        return c;
    }

    void food(world_t &from, world_t &to) {
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                char current = from[i][j];
                char result = ' ';
                int c = count(from, i, j);
                if (c == 3 || (c == 2 && current == '.')) {
                    result = '.';
                }
                to[i][j] = result;
            }
            to[i][N] = '\0';
        }

        print(to);
        usleep(1000 * 80);
    }

    void start() {
        while (true) {
            food(bar, bee);
            food(bee, bar);
        }
    }

};

const int World::neighbours[8][2] = { 
        1, 1, 
        1, 0, 
        1, -1, 
        0, -1, 
        -1, -1, 
        -1, 0, 
        -1, 1, 
        0, 1 
    };


int main() {
    ifstream fle("start.txt");
    int m, n;
    fle >> m >> n;
    World w(m, n, fle);
    w.start();

    return 0;
}
