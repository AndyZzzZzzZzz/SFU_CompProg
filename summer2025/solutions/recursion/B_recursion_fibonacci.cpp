#include <iostream>
#include <unordered_map>

using namespace std;

/*
Classic fibonacci problem with memoization applied
*/

int recur(unordered_map<int, int> & memo, int n){
    // first check whether we've seen this value before
    if(memo.count(n)) return memo[n];

    // compute the result and update memo map
    memo[n] = recur(memo, n - 1) + recur(memo, n - 2);

    // return the result
    return memo[n];
}

int main(){

    int n; cin >> n;
    unordered_map<int, int> memo;

    // these values pre-stored in memoization map acts as the base cases
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;

    cout << recur(memo, n) << endl;

    return 0;
}

