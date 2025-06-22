#include <iostream>
#include <string>

using namespace std;

int main(){

    int n; cin >> n;

    // flags to track whether the sequence is increasing or decreasing
    bool increase = true, decrease = true;
    // keep track of previous string
    string prev = "";
    for(int i = 0; i < n; i ++){
        
        string temp; cin >> temp;
        if(prev.length() == 0){
            prev = temp;
            continue;
        }
        if(temp > prev) decrease = false;
        else if(temp < prev) increase = false;
        prev = temp;
    }

    if((!increase && !decrease)) cout << "NEITHER" << endl;
    else if(increase) cout << "INCREASING" << endl;
    else if(decrease) cout << "DECREASING" << endl;
    

    return 0;
}