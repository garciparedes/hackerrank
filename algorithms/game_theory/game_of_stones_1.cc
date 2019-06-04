#include <iostream>

using namespace std;


bool game_of_stones(int n) {
    return n % 7 > 1;
}


int main() {
    int t, n;

    cin >> t;
    for (int i = 0; i < t; i += 1) {
        cin >> n;
        cout << (game_of_stones(n) ? "First" : "Second") << '\n';
    }

    return 0;
}