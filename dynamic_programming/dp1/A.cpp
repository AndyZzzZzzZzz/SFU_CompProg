#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <climits>
#include <stack>

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
    ll n; cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];

    vector<ll> dp(n+ 1, 0);
    dp[1] = abs(v[1] - v[0]);
    for(int j = 2; j < n; j ++){
        dp[j] = min(abs(v[j] - v[j - 2]) + dp[j-2], abs(v[j] - v[j -1]) + dp[j-1]);
    }
    cout << dp[n-1] << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
