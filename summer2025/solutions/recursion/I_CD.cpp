#include <iostream>
#include <vector>

using namespace std;

void recur(vector<int> & t, vector<int> & curr, int pos, int targ, int curr_sum, vector<int> & best, int& best_sum){
    // Base case 1: we have seen a sum closer to target, update best sum to keep track of it
    if(curr_sum > best_sum){
        best_sum = curr_sum;
        best = curr;
    }

    // Base case 2: We've used all CDs, return the whole function
    if(pos >= t.size()) return;

    // Only consider the current CD if taking it do not exceed the target
    if(curr_sum + t[pos] <= targ){
        curr.push_back(t[pos]);
        recur(t, curr, pos+1, targ, curr_sum + t[pos], best, best_sum);
        curr.pop_back();
    }
    // The other route is skip the current CD
    recur(t, curr, pos+1, targ, curr_sum, best, best_sum);

}

int main(){
    
    int n, t; 

    while(cin >> n >> t){

        vector<int> v(t);

        for(int i = 0; i < t; ++i) cin >> v[i];

        vector<int> curr, best;
        int best_sum = 0;

        recur(v, curr, 0, n,  0, best, best_sum);

        for(auto i : best) cout << i << ' ';
        cout << "sum:" << best_sum << endl; 

    }



    return 0;
}
