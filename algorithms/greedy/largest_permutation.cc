#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void largest_permutation(int k, vector<int> &vec) {
    vector<int>::iterator it_from, it_to;
    int expected;

    for (int i = 0; (i < k) & (i < vec.size()); i++) {
        it_to = vec.begin() + i;
        expected = vec.size() - i;
        if (*it_to == expected) {
            k += 1;
            continue;
        }
        it_from = find(it_to + 1, vec.end(), expected);
        iter_swap(it_from, it_to);
    }
}

int main() {
    int n, k, temp;
    vector<int> vec;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        vec.push_back(temp);
    }

    largest_permutation(k, vec);

    for (int value : vec) {
        cout << value << ' ';
    }
    cout << '\n';

    return 0;
}
