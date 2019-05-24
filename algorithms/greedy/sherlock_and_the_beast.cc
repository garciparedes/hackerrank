#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string generate_number(int threes, int fives) {
    stringstream ss;

    for (int i = 0; i < fives; i++) {
        ss << 5;
    }
    for (int i = 0; i < threes; i++) {
        ss << 3;
    }
    return ss.str();
}


string decent_number(int n) {
    int fives, threes;

    for (int i = 0; i <= n; i++) {
        threes = i;
        fives = n - i;

        if ((threes % 5 == 0) & (fives % 3 == 0)) {
            return generate_number(threes, fives);
        }
    }
    return "-1";
}


int main() {
    int t, n;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << decent_number(n) << '\n';
    }

    return 0;
}