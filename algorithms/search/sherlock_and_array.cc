#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool balanced_sums(vector<int> &vec) {
  unsigned long total, left;

  total = accumulate(vec.begin(), vec.end(), 0);

  left = 0;
  for (auto it = vec.begin(); it < vec.end(); it++) {

    if (total == 2 * left + *it) {
      return true;
    }

    left += *it;
  }

  return false;
}

int main() {
  int t, n, temp;
  vector<int> vec;

  cin >> t;
  for (int k = 0; k < t; k++) {

    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      vec.push_back(temp);
    }

    cout << (balanced_sums(vec) ? "YES" : "NO") << '\n';

    vec.clear();
  }
  return 0;
}