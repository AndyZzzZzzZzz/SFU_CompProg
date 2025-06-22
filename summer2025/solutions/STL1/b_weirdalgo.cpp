#include <iostream>

using namespace std;

int main(){

    long long n; cin >> n;

    while(n != 1){
        cout << n << ' ';
        // 0 is false by default, all other number is true
        if(n % 2) n = n * 3 + 1;
        else n /= 2;
    }

    cout << n << '\n'; 
    return 0;
}