#include <iostream>

using namespace std;

bool tower_breakers(int n, int m) {
    return (m != 1) && (n % 2 != 0);
}

int main() {
    int t, n, m;

    cin >> t;
    for (int i = 0; i < t; i += 1) {
        cin >> n >> m;
        cout << (tower_breakers(n, m) ? 1 : 2) << '\n';
    }

    return 0;
}