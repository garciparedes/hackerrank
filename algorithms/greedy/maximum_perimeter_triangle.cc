#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maximum_perimeter_triangle(vector<int> &sticks) {
  sort(sticks.begin(), sticks.end(), greater<int>());

  for (auto it_a = sticks.begin(); it_a < sticks.end() - 2; it_a += 1) {
    if (*it_a < *(it_a + 1) + *(it_a + 2)) {
      return {*(it_a + 2), *(it_a + 1), *it_a};
    }
  }

  return {};
}

int main() {
  int n, temp;
  vector<int> sticks;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    sticks.push_back(temp);
  }

  vector<int> triangle = maximum_perimeter_triangle(sticks);
  if (triangle.size() == 3) {
    cout << triangle[0] << ' ' << triangle[1] << ' ' << triangle[2] << '\n';
  } else {
    cout << -1 << '\n';
  }

  return 0;
}