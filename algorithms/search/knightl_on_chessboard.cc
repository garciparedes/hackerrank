#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void explore_board(vector<vector<int>> &board, int n, int a, int b, int x = 0, int y = 0, int deep = 0) {
    if (x < 0 || n <= x || y < 0 || n <= y) {
        return;
    }

    if (board[x][y] <= deep) {
        return;
    }

    board[x][y] = deep;

    if (x + 1 == n && y + 1 == n) {
        return;
    }

    explore_board(board, n, a, b, x + a, y + b, deep + 1);
    explore_board(board, n, a, b, x + a, y - b, deep + 1);
    explore_board(board, n, a, b, x - a, y + b, deep + 1);
    explore_board(board, n, a, b, x - a, y - b, deep + 1);
    explore_board(board, n, a, b, x + b, y + a, deep + 1);
    explore_board(board, n, a, b, x + b, y - a, deep + 1);
    explore_board(board, n, a, b, x - b, y + a, deep + 1);
    explore_board(board, n, a, b, x - b, y - a, deep + 1);
}

vector<vector<int>> knightl_on_a_chessboard(int n) {
    vector<vector<int>> solution;
    int length;

    for (int i = 1; i < n; i++) {
        vector<int> row;

        for (int j = 1; j < n; j++) {
            if (i <= j) {
                vector<vector<int>> board(n, vector<int>(n, INT_MAX));
                explore_board(board, n, i, j);
                length = (board[n - 1][n - 1] != INT_MAX) ? board[n - 1][n - 1] : -1;
                row.push_back(length);
            } else {
                row.push_back(solution[j - 1][i - 1]);

            }
        }
        solution.push_back(row);
    }
    return solution;
}

int main() {
    int n;

    cin >> n;
    for (const vector<int> &row : knightl_on_a_chessboard(n)) {
        for (int value : row) {
            cout << value << ' ';
        }
        cout << '\n';
    }

    return 0;
}