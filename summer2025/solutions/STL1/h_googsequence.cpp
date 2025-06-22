#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){

    int n; cin >> n;

    // use unordered map for value -> frequencies mapping
    unordered_map<int, int> mp;
    while(n --){

        int curr; cin >> curr;
        mp[curr] ++;
    }

    int res = 0;
    /*
        For each element there are two options:
        1.  remove all occurence of that element
        2.  delete occurence until we reach the element count

    */
    // loop through all pairs
    for(auto pairs : mp){
        if(pairs.second < pairs.first) res += pairs.second;
        else if(pairs.second > pairs.first) res += pairs.second - pairs.first;
    }
    cout << res << '\n';
    return 0;
}