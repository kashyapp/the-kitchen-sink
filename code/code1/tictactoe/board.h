#include <ostream>
#include <vector>

using std::vector;
using std::ostream;

class Board {
    vector< vector<bool> > grid;
    bool isComplete;
    int winner;

    public:
        Board(int size);
        bool mark(int player, int x, int y);
        int getWinner() const;
        ostream& operator<<(ostream&) const;
};
