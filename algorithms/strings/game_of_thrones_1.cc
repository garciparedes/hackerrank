#include <iostream>
#include <map>

using namespace std;

bool is_game_of_thrones(const string &text) {
  bool result = true;

  map<char, int> histogram;

  for (char v : text) {
    histogram[v] += 1;
  }

  bool with_odd = false;
  for (pair<char, int> value : histogram) {
    if (value.second % 2 != 0) {
      if (with_odd) {
        result = false;
      } else {
        with_odd = true;
      }
    }
  }
  return result;
}

int main() {
  string text;
  cin >> text;
  cout << (is_game_of_thrones(text) ? "YES" : "NO") << '\n';
}