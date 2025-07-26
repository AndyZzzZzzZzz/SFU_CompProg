#include <bits/stdc++.h>

using namespace std;

#define ll long long

int p, ok = 0; 

string super(string n) {
  if (n.length() <= 1) return n;
  ll sum = 0; 
  for(int i = 0; i < n.length(); i++) {
    ll v = n[i] - '0';
    if (!ok) sum += (p * v);
    else sum += v; 
  }
  if (!ok) ok = 1; 
  string t = "";
  while (sum > 0) {
    t.push_back((sum % 10) + '0');
    sum /= 10; 
  }
  return super(t);
}
void sol() {
  string n;
  cin >> n >> p;
  cout << super(n) << "\n";
}
int main(void) { 	
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  sol(); 
}

