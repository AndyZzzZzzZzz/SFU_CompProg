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
    string s = "";
    string tmp;
    while(cin >> tmp){
        for(char c : tmp){
            if(isalpha(c)) s += tolower(c);
        }
    }
    
    ll n = s.size();
    vector<vector<ll>> dp(n, vector<ll>(n, LONG_MAX));

    for(int length = 2; length <= n; ++length){
        // right index of the substring to check for
        for(int r = 0; r <= n -length; ++r){
            int l = r + length - 1;

            if(length == 2) dp[r][l] = (s[r] == s[l]) ? 0 : 1;
            else{
                if(s[r] == s[l]) dp[r][l] = dp[r+1][l-1];
                else dp[r][l] = 1 + min(dp[r+1][l], dp[r][l-1]);
            }
        }
    }
    cout << dp[0][n-1] << '\n';

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
