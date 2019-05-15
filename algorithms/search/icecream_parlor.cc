#include <iostream>
#include <vector>
using namespace std;

vector<long> ice_cream_parlor(int m, vector<int> arr) {
  for (auto it_i = arr.begin(); it_i < arr.end(); it_i++) {
    for (auto it_j = it_i + 1; it_j < arr.end(); it_j++) {
      if (*it_i + *it_j == m) {
        return {it_i - arr.begin() + 1, it_j - arr.begin() + 1};
      }
    }
  }
  return {};
}

int main() {

  int t, m, n, temp;
  cin >> t;

  for (int t_itr = 0; t_itr < t; t_itr++) {
    cin >> m;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      arr.push_back(temp);
    }

    vector<long> result = ice_cream_parlor(m, arr);
    cout << result[0] << ' ' << result[1] << "\n";
  }

  return 0;
}

