#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<pair<int, int>> jim_orders(vector<pair<int, int>> &orders) {

    int i = 1;
    for (auto it = orders.begin(); it < orders.end(); it += 1) {
        *it = pair<int, int>(i++, it->first + it->second);
    }

    sort(orders.begin(), orders.end(), [](pair<int, int> const &a, pair<int, int> const &b) {
        if (a.second == b.second) {
            return (a.first < b.first);
        }
        return (a.second < b.second);
    });

    return orders;
}

int main() {
    int n, id, time;

    vector<pair<int, int>> orders;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id >> time;
        orders.emplace_back(id, time);
    }

    for (auto value : jim_orders(orders)) {
        cout << value.first << ' ';
    }
    cout << '\n';


    return 0;
}