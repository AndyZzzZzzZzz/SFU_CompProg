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
    string s, t; cin >> s >> t;
    
    int n = s.size(), m = t.size();
    // states is the lnegth of the common subsequences we have
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 0; i < n; ++ i){
        for(int j = 0 ; j < m; ++ j){
            if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j]+1;
            else dp[i+1][j+1] = (dp[i][j+1] > dp[i+1][j]) ? dp[i][j+1] : dp[i+1][j];
        }
    }
    
    string res = "";
    int i = n, j = m;

    while( i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            res+=s[i-1];
            i--; j--;
        }
        else if(dp[i][j-1] > dp[i-1][j]) j--;
        else i--;
    }

    reverse(res.begin(), res.end());
    cout << res <<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
