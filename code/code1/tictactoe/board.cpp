#include "board.h"

#include <iostream>

using std::cout;
using std::endl;

Board::Board(int size) :
    grid(size, vector<bool>(size, false)),
    isComplete(false) {
}

bool Board::mark(int player, int x, int y) {
    return true;
}

int Board::getWinner() const {
    return 0;
}

ostream& Board::operator<<(ostream& os) const {
    return os;
}

int main() {
    Board b(4);
    cout << b << endl;
}
