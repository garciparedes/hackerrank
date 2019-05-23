#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int beautiful_pairs(vector<int> &arr, vector<int> &brr) {
  vector<bool> brr_free(brr.size(), true);

  int count = 0;
  for (int a_i : arr) {
    for (int j = 0; j < brr.size(); j++) {
      if (brr_free[j] & (a_i == brr[j])) {
        count += 1;
        brr_free[j] = false;
        break;
      }
    }
  }
  if (find(brr_free.begin(), brr_free.end(), true) != brr_free.end()) {
    count += 1;
  } else {
    count -= 1;
  }

  return count;
}

int main() {
  int n, temp;
  vector<int> arr;
  vector<int> brr;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    arr.push_back(temp);
  }
  for (int i = 0; i < n; i++) {
    cin >> temp;
    brr.push_back(temp);
  }

  cout << beautiful_pairs(arr, brr) << '\n';
}