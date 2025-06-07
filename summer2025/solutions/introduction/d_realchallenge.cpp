#include <iostream>
#include <cmath>
#include <iomanip> // precision managing

using namespace std;

int main(){
    
    // using sqrtl for long double
    long double n; cin >> n;

    // default square root function
    long double perim = sqrtl(n);

    // use fixed to avoid scientific notation i.e. 123456,0 instead of 1.23456e+05
    // setprecision(10) controls how many digits are pinted after the decimal point (when used with fixed)
    cout << fixed << setprecision(10) << 4.0 * perim << '\n' ;

    return 0 ;
}