#include <iostream>
#include <vector>
#include <set>

using namespace std;

void recur(vector<int>& v, int pos, vector<int>& tmp, set<vector<int>>&seen, int targ, int sum, bool &found){

    // Base case 1: current sum reaches the target
    if(sum == targ){
        // If we've seen the exact combination, ignore it
        if(seen.count(tmp)) return;
        seen.insert(tmp);
        
        // Construct and print the combination
        found = true;
        for(int i = 0; i < tmp.size(); ++i){
            cout << tmp[i];
            if(i!= tmp.size()-1) cout << '+';
        }

        cout << endl;
        return;
    }
    // Base case 2: current sum exceed target and is invalid
    if(sum > targ || pos >= v.size()) return;

    // Backtracking to try all possible combinations
    for(int i = pos; i < v.size(); ++i){
        
        tmp.push_back(v[i]);
        recur(v, i + 1, tmp, seen, targ, sum + v[i], found);
        tmp.pop_back();
    }

}

int main(){
    
    int t, n; 

    while(cin >> t >> n && t && n){
        
        vector<int> v(n), tmp;
        set<vector<int>> seen;
        bool found = false;

        for(int i = 0; i < n; ++i) cin >> v[i];
        
        cout << "Sums of " << t << ':' << endl;
        recur(v, 0, tmp, seen, t, 0, found);
        if(!found) cout << "NONE" << endl;
    }

    return 0;
}
