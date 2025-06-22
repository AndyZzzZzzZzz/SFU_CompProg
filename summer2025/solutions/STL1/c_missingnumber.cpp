#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n; cin >> n;
    // marks whether we see each number
    // pos 0 -> 1, pos 1 -> 2 ...
    vector<int> v(n, 0);

    // starts marking
    for(int i = 0; i < n - 1; i ++){
        int num; cin >> num;
        v[num - 1] += 1;
    }

    // 0 means we didn't see it, 1 means we marked it before
    for(int i = 0; i < n; i ++){
        if(!v[i]){
            cout << i + 1 << '\n';
            break;
        }
    }
    
    return 0;
}