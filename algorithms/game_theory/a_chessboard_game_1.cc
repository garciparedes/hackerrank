#include <iostream>

using namespace std;

bool chessboard_game(int x, int y, bool player = true) {

    if (!((1 <= x) && (x <= 15) && (1 <= y) && (y <= 15))) {
        return player;
    }

    return ((chessboard_game(x - 2, y + 1, !player) == player) ||
            (chessboard_game(x - 2, y - 1, !player) == player) ||
            (chessboard_game(x + 1, y - 2, !player) == player) ||
            (chessboard_game(x - 1, y - 2, !player) == player)) == player;
}

int main() {
    int t, x, y;

    cin >> t;
    for (int i = 0; i < t; i += 1) {
        cin >> x >> y;
        cout << (chessboard_game(x, y) ? "First" : "Second") << '\n';
    }

    return 0;
}