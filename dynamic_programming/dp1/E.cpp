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
    int n, k; cin >> n >> k;
        
    vector<int> stones(n);
    for(int i = 0 ; i< n; ++i) cin >> stones[i];
    
    // boolean game state: i -> true we can win when i stones is left
    vector<int> dp(k+1, 0);
    
    for(int i = 1; i <= k; ++i){
        // attempt all moves
        for(int s : stones){
            if(s <= i && !dp[i-s]) {dp[i] = 1; break;}
        }
    }
    if(dp[k]) cout << "First" << '\n';
    else cout << "Second" << '\n';




    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
