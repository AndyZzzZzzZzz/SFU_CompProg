#include <iostream>
#include <vector>

using namespace std;

int recur(vector<int> &nums, int pos){

    // base case, we are pass the last number in array
    if(pos >= nums.size()) return 0;

    // save the number at pos in the current call stack
    // recursively calls onto the next number in array
    return nums[pos] + recur(nums, pos + 1);
}
int main(){

    int n; cin >> n;
    vector<int> result;

    while(n --){

        int size; cin >> size;

        vector<int> nums(size);

        for(int i = 0; i < size; ++i) cin >> nums[i];

        result.push_back(recur(nums, 0));
    }

    for(int i = 0; i < result.size(); ++i){
        cout << "Case " << i + 1 << ": " << result[i] << endl;
    }

    return 0;
}