#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <climits>
#include <stack>
#include <algorithm>
#include <cctype> 

using namespace std;

using ll = long long;
using ld = long double;
template<class T> bool chmin(T& a, const T& b){ if(b < a){ a = b; return true; } return false; }
template<class T> bool chmax(T& a, const T& b){ if(a < b){ a = b; return true; } return false; }

#ifdef LOCAL
  #define dbg(x) cerr << "[dbg] " << #x << " = " << (x) << '\n'
#else
  #define dbg(x) ((void)0)
#endif

const ll INF64 = (1LL<<62);
const int INF32 = (1<<30);
const int MOD   = 1'000'000'007; 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; 

void solve(){
    
    int n; cin >> n;
    vector<ll> v(n);

    for(int i = 0; i < n; ++i ){
        cin >> v[i];
    }
    
    vector<ll> dp;
    dp.reserve(n);
    
    for(int i = 0; i <n; ++i){
        
        auto it = lower_bound(dp.begin(), dp.end(), v[i]);

        if(it == dp.end()) dp.push_back(v[i]);
        else *it = v[i];

    }
    cout << dp.size() << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
