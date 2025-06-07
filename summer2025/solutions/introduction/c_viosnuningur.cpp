#include <iostream>
#include <string>

using namespace std;

int main(){

    // read a line of input as string
    string input; getline(cin, input);
    // use the reverse function to reverse a string in-place
    reverse(input.begin(), input.end());
    cout << input << '\n';

    return 0;
}