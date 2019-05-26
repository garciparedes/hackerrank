#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int toys(vector<int> weights) {
  int counter, lower;

  sort(weights.begin(), weights.end());

  counter = 1;
  lower = weights[0];
  for (int w : weights) {
    if (lower + 4 < w){
      counter += 1;
      lower = w;
    }
  }

  return counter;
}

int main() {
  int n, temp;
  vector<int> weights;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    weights.push_back(temp);
  }

  cout << toys(weights) << '\n';

  return 0;
}