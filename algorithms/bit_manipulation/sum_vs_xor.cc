#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


unsigned long long sum_xor(int64_t number) {
    int64_t counter = 0;

    for (int64_t other = 1; 0 < other && other < number; other <<= 1) {
        counter += !(number & other);
    }

    return (static_cast<int64_t>(1) << counter);

}


int main() {
    unsigned long long n;

    cin >> n;

    cout << sum_xor(n) << '\n';

    return 0;
}