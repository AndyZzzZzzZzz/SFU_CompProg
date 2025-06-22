#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main(){

    // read total number of test cases
    int n; cin >> n;
    // vector to hold the total results
    vector<int> v;

    while(n --){
        // read in number of cities
        int t; cin >> t;
        // unordered set to hold the cities
        unordered_set<string> st;
        for(int i = 0; i < t; i ++){
            string s; cin >> s;
            st.insert(s);
        }
        v.push_back(st.size());
    }

    for(auto i : v){
        cout << i << '\n';
    }
    return 0;
}