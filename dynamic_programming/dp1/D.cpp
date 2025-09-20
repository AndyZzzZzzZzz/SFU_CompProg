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
    int n; cin >> n;
    vector<vector<ll>> v;

    for(int i = 0; i < n; ++ i){
        int a, b, c; cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
    
    vector<vector<ll>> dp(n, vector<ll>(3));

    dp[0][0] = v[0][0];
    dp[0][1]= v[0][1];
    dp[0][2] = v[0][2];
    for(int i = 1; i < n; ++ i){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + v[i][0];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + v[i][1];
        dp[i][2] = max(dp[i-1][1], dp[i-1][0]) + v[i][2];
    }
    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]))<< '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
