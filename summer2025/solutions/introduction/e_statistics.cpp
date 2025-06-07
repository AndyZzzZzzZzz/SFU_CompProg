#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){

    int n ;
    // a vector to hold results
    vector<vector<int>> res;
    while(cin >> n){
        // set variable to a maximum / minimum integer value
        int _max = INT_MIN;
        int _min = INT_MAX;
        // loop through all the candidates and compute local min/max on the fly
        for(int i = 0; i < n; i ++){
            int curr; cin >> curr;
            // update maximum and minimum candidate
            _max = max(_max, curr);
            _min = min(_min, curr);
        }
        // when saving the result, calculate the range using the final max / min candidate
        res.push_back({_min, _max, _max - _min});
    }

    for(int i = 0; i < res.size(); i ++){
        cout << "Case " << i + 1 << ": " << res[i][0] << " " << res[i][1] << " " << res[i][2] << '\n';
    }
    return 0;
}