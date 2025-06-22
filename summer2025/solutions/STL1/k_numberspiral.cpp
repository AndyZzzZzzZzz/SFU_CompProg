#include <iostream>
#include <vector>
using namespace std;
int main(){

    int n; cin >> n;

    /*
        Intuition:
        If layer is even, top right value of the layer equals to layer^2
        -   x == layer -> val = layer^2 - y + 1
        -   y == layer -> val = (layer - 1)^2 + x
        If layer is odd, bottom left value is layer^2
        -   y == layer -> val = layer^2 - x + 1
        -   x == layer -> val = (layer - 1)^2 + y
        
    */

    vector<long long> res;
    while(n --){
        // for tuple (row, col): col -> x, row -> y
        long long x ,y; cin >> y >> x;
        // determine which layer this coordinate is on
        long long layer = max(x, y);
        // determine the position squared
        long long square = 1LL * (layer-1) * (layer - 1);

        // apply formula for even and odd cases
        if(square % 2){
            if(y == layer) res.push_back(layer * layer - x + 1);
            else res.push_back((layer - 1) * (layer - 1) + y);
        }else{
            if(x == layer) res.push_back(layer * layer - y + 1);
            else res.push_back((layer-1) * (layer-1) + x);
        }
    }

    for(auto v : res) cout << v << '\n';
    return 0;
}