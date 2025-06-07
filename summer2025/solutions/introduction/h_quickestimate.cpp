#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(){

    // 10^100 is too large for any numerical variable
    // use a string instead
    
    int n; cin >>n;
    vector<string> v(n);
    // read inputs
    for(int i = 0; i < n; i ++) cin >> v[i];
    // ouput length of all strings
    for(int i = 0; i < n; i ++){
        cout << v[i].length() << '\n';
    }

    return 0;
}