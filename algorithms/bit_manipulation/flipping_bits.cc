#include <iostream>
#include <vector>
#include <numeric>
#include <bitset>

using namespace std;


unsigned long flipping_bits(unsigned long number) {
    bitset<32> bits(number);
    bits = ~bits;
    return bits.to_ulong();
}


int main() {
    int q;
    unsigned long number;

    cin >> q;
    for (int i = 0; i < q; i += 1) {
        cin >> number;
        cout << flipping_bits(number) << '\n';
    }
    return 0;
}