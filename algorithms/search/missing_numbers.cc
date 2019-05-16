#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> vector_to_counter(const vector<int> &vec) {
  map<int, int> counter;
  for (auto value : vec) {
    auto it = counter.find(value);
    if (it != counter.end()) {
      it->second += 1;
    } else {
      counter.insert(make_pair(value, 1));
    }
  }
  return counter;
}

vector<int> missing_numbers(const vector<int>& arr, vector<int> brr) {
  vector<int> result;
  map<int, int> arr_counter = vector_to_counter(arr);
  map<int, int> brr_counter = vector_to_counter(brr);

  for (auto it_brr : brr_counter) {
    auto it_arr = arr_counter.find(it_brr.first);
    if (it_arr == arr_counter.end() || it_arr->second != it_brr.second) {
      result.push_back(it_brr.first);
    }
  }

  sort(result.begin(), result.end());

  return result;
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

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    brr.push_back(temp);
  }

  for (auto value : missing_numbers(arr, brr)) {
    cout << value << ' ';
  }
  cout << '\n';

  return 0;
}