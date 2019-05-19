#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool grid_challenge(vector<string> &vec) {
  transform(vec.begin(), vec.end(), vec.begin(), [](string value) -> string {
    sort(value.begin(), value.end());
    return value;
  });

  for (int i = 0; i < vec.size() - 1; i++) {
    for (int j = 0; j < vec.size(); j++) {
      if (vec[i][j] <= vec[i + 1][j]) {
        continue;
      }
      return false;
    }
  }
  return true;
}

int main() {
  int t, n;
  string temp;
  vector<string> vec;

  cin >> t;
  for (int k = 0; k < t; k++) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      vec.push_back(temp);
    }

    cout << (grid_challenge(vec) ? "YES" : "NO") << '\n';

    vec.clear();
  }

  return 0;
}
