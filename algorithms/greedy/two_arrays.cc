#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool two_arrays(int k, vector<int> &arr, vector<int> &brr) {
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end(), greater<int>());

    for (int i = 0; i < arr.size(); i += 1) {
        if (arr[i] + brr[i] < k) {
            return false;
        }
    }

    return true;
}

int main() {
    int q, n, k, temp;
    vector<int> arr, brr;

    cin >> q;
    for (int itr = 0; itr < q; itr += 1) {

        cin >> n >> k;
        for (int i = 0; i < n; i += 1) {
            cin >> temp;
            arr.push_back(temp);
        }
        for (int i = 0; i < n; i += 1) {
            cin >> temp;
            brr.push_back(temp);
        }

        cout << (two_arrays(k, arr, brr) ? "YES" : "NO") << '\n';


        arr.clear();
        brr.clear();
    }


    return 0;
}