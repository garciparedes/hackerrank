#include <iostream>
#include <string>
#include <utility>

using namespace std;

int palindrome_index(string &word, string::iterator left, string::iterator right, bool used) {
    if (!(left < right)) {
        return -1;
    }

    if (*left != *right) {
        if (used) {
            return -2;
        }

        if (palindrome_index(word, left + 1, right, true) == -1) {
            return left - word.begin();
        }

        if (palindrome_index(word, left, right - 1, true) == -1) {
            return right - word.begin();
        }

        return -1;
    }

    return palindrome_index(word, left + 1, right - 1, used);

}

int palindrome_index(string &word) {
    return palindrome_index(word, word.begin(), word.end() - 1, false);
}

int main() {
    int q;
    string word;

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> word;
        cout << palindrome_index(word) << '\n';
    }

    return 0;
}