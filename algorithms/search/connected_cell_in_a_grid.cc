#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int connected_cell(vector<vector<int>> &board) {
    int region_id = 2;

    int cell;
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (!board[i][j]) {
                    continue;
                }

                cell = board[i][j];
                if (cell == 1) {
                    cell = region_id++;
                }

                if (i > 0 && board[i - 1][j]) {
                    cell = max(cell, board[i - 1][j]);
                }
                if (i < board.size() - 1 && board[i + 1][j]) {
                    cell = max(cell, board[i + 1][j]);
                }
                if (j > 0 && board[i][j - 1]) {
                    cell = max(cell, board[i][j - 1]);
                }
                if (j < board[i].size() - 1 && board[i][j + 1]) {
                    cell = max(cell, board[i][j + 1]);
                }
                if (i > 0 && j < board[i].size() - 1 && board[i - 1][j + 1]) {
                    cell = max(cell, board[i - 1][j + 1]);
                }
                if (j > 0 && i < board.size() - 1 && board[i + 1][j - 1]) {
                    cell = max(cell, board[i + 1][j - 1]);
                }
                if (i > 0 && j > 0 && board[i - 1][j - 1]) {
                    cell = max(cell, board[i - 1][j - 1]);
                }
                if (i < board.size() - 1 && j < board[i].size() - 1 && board[i + 1][j + 1]) {
                    cell = max(cell, board[i + 1][j + 1]);
                }

                if (board[i][j] != cell) {
                    board[i][j] = cell;
                    changed = true;
                }

            }
        }
    }


    map<int, int> counter;
    for (const auto &row: board) {
        for (auto cell : row) {
            if (!cell) {
                continue;
            }

            auto count = counter.find(cell);
            if (count == counter.end()) {
                count = counter.insert(make_pair(cell, 0)).first;
            }
            count->second += 1;
        }
    }


    auto max_region = max_element(counter.begin(), counter.end(),
                                  [](const pair<int, int> &p1, const pair<int, int> &p2) {
                                      return p1.second < p2.second;
                                  });
    return max_region->second;
}


int main() {
    int n, m;

    cin >> n >> m;
    vector<vector<int>> board(n);
    for (int i = 0; i < n; i++) {
        board[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    cout << connected_cell(board) << '\n';


    return 0;
}