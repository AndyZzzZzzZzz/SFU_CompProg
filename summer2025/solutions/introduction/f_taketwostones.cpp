#include <iostream>

using namespace std;
int main(){

    int n; cin >> n;
    /* 
        condition ? outcome A : outcome B is equivalent to
    
        if condition:
            outcome A
        else:
            outcome B
    */
    cout << ((n % 2 == 0) ? "Bob" : "Alice") << '\n';


    return 0;
}