#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long marcs_cakewalk(vector<int> &vec) {
  sort(vec.begin(), vec.end(), greater<int>());

  long long result = 0;
  for (int i = 0; i < vec.size(); i++) {
    result += static_cast<long long>(pow(2, i)) * vec[i];
  }
  return result;
}

int main() {
  int n, temp;
  vector<int> vec;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    vec.push_back(temp);
  }

  cout << marcs_cakewalk(vec) << '\n';

  return 0;
}