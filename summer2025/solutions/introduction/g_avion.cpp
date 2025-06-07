#include <iostream>
#include <string>

using namespace std;

int main(){

    // boolean flag to track whether we found FBI
    bool find = false;
    // since the input is fixed, use a fixed for loop
    for(int i = 0; i < 5; i ++){
        string tmp; cin >> tmp;
        // default string function to get the first index of apperance
        size_t pos = tmp.find("FBI");
        // npos is end of position, which is equivalent to -1
        if(pos != string::npos){
            cout << i+1 << " ";
            find = true;
        }
    }
    // If we didn't find FBI, print he got away
    if(! find)  cout << "HE GOT AWAY!" << '\n';
  

    return 0;
}