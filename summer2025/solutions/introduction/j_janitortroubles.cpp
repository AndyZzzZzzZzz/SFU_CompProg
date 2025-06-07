#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){

    int a, b, c, d; cin >> a >> b >> c >> d;

    // search up Brahmagupta's formula
    // calculate the semiperimeter
    long double s = (a + b + c + d)/2.0L;

    // apply formula
    long double K = sqrtl((s - a) * (s - b) * (s - c) * (s - d));

    cout << fixed << setprecision(10) << K << endl;
    return 0;
}