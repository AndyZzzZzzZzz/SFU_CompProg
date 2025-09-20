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
    int n, w; cin >> n >> w;
    vector<ll> values(n);
    vector<ll> costs(n);
    for(int i = 0; i < n; ++i){
        cin >> costs[i] >> values[i];
    }
    
    vector<vector<ll>> dp(n +1, vector<ll>(w+1,0));

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= w; ++j){
            // if no item or knapsack capacity is 0
            if(i == 0 || j == 0) dp[i][j] = 0;
            else{
                ll pick = 0;
                // able to pick up the element
                if(costs[i-1] <= j){
                    pick = values[i-1] + dp[i-1][j - costs[i-1]];
                }
                // Skip this element
                ll not_pick = dp[i-1][j];
                dp[i][j] = max(pick, not_pick);
            }
        }
    }
    cout << dp[n][w] << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
