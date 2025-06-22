#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;
int main(){

    // hold the amount of numbers each line
    int n;
    vector<string> res;
    // read in inputs 
    while(cin >> n){
        
       // read in current test values
       vector<int> curr(n);
       for(int i = 0; i < n; i ++) cin >> curr[i];

       // use a set to store unique absolute diffs
       unordered_set<int> diff;
       for(int i = 1; i < n; i ++){
            diff.insert(abs(curr[i] - curr[i - 1]));
       }

       // check for Jolly conditions
       // we must have all values between 1 and n - 1
       bool jolly = true;
       for(int i = 1; i < n; i ++){
        if(diff.find(i) == diff.end()){
            jolly = false;
            break;
        }
       }
    
       // evaluate the condition jolly, if true push Jolly if not push Not jolly
       // this is equivalent to a if else condition check
       res.push_back(jolly ? "Jolly" : "Not jolly");
    }
    for(auto r : res) cout << r << '\n';
    return 0;
}