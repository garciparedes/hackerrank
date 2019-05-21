#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

int luck_balance(unsigned long k, vector<pair<int, bool>> &contests) {
  int luck = 0;

  vector<int> important;
  for (auto contest : contests) {
    if (contest.second == 0) {
      luck += contest.first;
    } else {
      important.push_back(contest.first);
    }
  }

  sort(important.begin(), important.end(), greater<int>());

  luck += accumulate(important.begin(), important.begin() + min(k, important.size()), 0);
  luck -= accumulate(important.begin() + min(k, important.size()), important.end(), 0);

  return luck;
}

int main() {
  int n, k, l_temp, t_temp;
  vector<pair<int, bool>> contests;

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> l_temp >> t_temp;
    contests.emplace_back(l_temp, t_temp);
  }

  cout << luck_balance(k, contests) << '\n';

  return 0;
}