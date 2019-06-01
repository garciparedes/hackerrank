#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximum_toys(vector<int> &prices, int k) {
    sort(prices.begin(), prices.end());

    int toys = 0;
    int price = 0;

    auto it = prices.begin();
    while (price + *it <= k) {
        price += *it;
        toys += 1;
        it += 1;
    }

    return toys;
}


int main() {
    int n, k, temp;
    vector<int> vec;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        vec.push_back(temp);
    }

    cout << maximum_toys(vec, k);

    return 0;
}
