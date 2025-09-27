#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-8;
typedef long long ll;

ll cross(ll x1, ll y1, ll x2, ll y2){
    return (x1 * y2) - (x2 * y1);
}

bool on_segment(ll x1, ll y1, ll x2, ll y2, ll x, ll y) {
    return min(x1, x2) <= x && x <= max(x1, x2) &&
           min(y1, y2) <= y && y <= max(y1, y2);
}

int main(){
    int n; cin >> n;
    while(n--){
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        
        ll sideA = cross(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
        ll sideB = cross(x2 - x1, y2 - y1, x4 - x1, y4 - y1);
        ll sideC = cross(x4 - x3, y4 - y3, x1 - x3, y1 - y3);
        ll sideD = cross(x4 - x3, y4 - y3, x2 - x3, y2 - y3);

        if ((sideA > 0 && sideB < 0 || sideA < 0 && sideB > 0) &&
            (sideC > 0 && sideD < 0 || sideC < 0 && sideD > 0)) {
            cout << "YES" << '\n';
            continue;
        }

        // Colinear or endpoint touch cases
        if (sideA == 0 && on_segment(x1, y1, x2, y2, x3, y3)) { cout << "YES" << '\n'; continue; }
        else if (sideB == 0 && on_segment(x1, y1, x2, y2, x4, y4)) { cout << "YES" << '\n'; continue; }
        else if (sideC == 0 && on_segment(x3, y3, x4, y4, x1, y1)) { cout << "YES" << '\n'; continue; }
        else if (sideD == 0 && on_segment(x3, y3, x4, y4, x2, y2)) { cout << "YES" << '\n'; continue; }

        cout << "NO" << '\n';
    }
    return 0;
}