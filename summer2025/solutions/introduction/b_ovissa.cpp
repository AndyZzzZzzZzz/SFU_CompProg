#include <iostream>
#include <string>

using namespace std;

int main(){
    
    // string variable
    string input;
    // read a line of input as string
    getline(cin, input);
    // use default string length function 
    cout << input.length() << '\n';
    
    return 0;
}