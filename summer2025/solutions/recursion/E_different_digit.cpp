#include <iostream>
#include <vector>

using namespace std;

// Approach 1: Iteration within recursion
int recur(int n, int m) {
    if (n >= m) return 0;

    int temp = n;
    // Digit array to track 0 to 9
    int arr[10] = {0};
    bool valid = true;

    // Track the frequency of each digit within n
    while (temp != 0) {
        int digit = temp % 10;
        if (arr[digit]) {
            valid = false;
            break;
        }
        arr[digit] = 1;
        temp /= 10;
    }
    // Accumulate and move on to the next digit
    return (valid ? 1 : 0) + recur(n + 1, m);
}

// Approach 2: Recursion with no loop
bool has_unique_digits(int curr, vector<int>& freq) {
    // base case: donw with current iteration
    if (curr == 0) return true;
    // loop logic replaced by recursive calls
    int digit = curr % 10;
    if (freq[digit]) return false;
    freq[digit] = 1;
    bool result = has_unique_digits(curr / 10, freq);
    freq[digit] = 0; // Undo for next use (backtrack)

    return result;
}

// Recursion function for accumulation
int recur_no_loop(int n, int m) {
    if (n >= m) return 0;
    vector<int> freq(10, 0);
    int valid = has_unique_digits(n, freq) ? 1 : 0;
    return valid + recur_no_loop(n + 1, m);
}

int main(){

    int n, m;
    vector<int> v;
    vector<int> freq(10, 0);
    while(cin >> n >> m){
        v.push_back(recur_no_loop(n, m+1));
    }

    for(int i : v){
        cout << i << endl;
    }
    return 0;
}