#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

    int n; cin >> n;
    // frequence map: box size -> count
    unordered_map<int, int> mp;


    // keep track of the maxium frequency we've seen
    int max_freq = 1;
    while(n --){
        int b; cin >> b;

        mp[b] ++;
        max_freq = max(max_freq, mp[b]);
    }

    cout << max_freq << '\n';
    
    return 0;
}