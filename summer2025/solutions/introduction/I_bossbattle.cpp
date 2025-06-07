#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    // base case
    if (n <= 3) {
        cout << 1 << "\n";
    } else {
        // observe the pattern
        cout << (n - 2) << "\n";
    }
    return 0;
}
