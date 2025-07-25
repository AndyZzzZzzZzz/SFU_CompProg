#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long long, int> memo;

int recur(long long n) {
    // Base case 1: we hit 1
    if (n == 1) return 1;
    // base case 2: we've computed this value before
    if (memo.count(n)) return memo[n];

    // break recursive case into even / odd
    int result = 1 + (n % 2 ? recur(3 * n + 1) : recur(n / 2));

    memo[n] = result;
    return result;
}

int max_cycle(int cur, int top) {
    if (cur > top) return 0;
    return max(recur(cur), max_cycle(cur + 1, top));
}

int main() {
    int bot, top;
    while (cin >> bot >> top) {
        int l = min(bot, top), r = max(bot, top);
        int res = max_cycle(l, r);
        cout << bot << ' ' << top << ' ' << res << endl;
    }
    return 0;
}