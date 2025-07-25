#include <iostream>
#include <string>
#include <vector>

using namespace std;

void recur(string s, int pos, string curr){

    // Base case, we finished inserting the last character
    if(pos == s.length()){ cout << curr << '\n';  return; }

    /*
        recur("abc", 0, "")
        └── insert 'a' → "a"
            ├── recur("abc", 1, "a")
            │   ├── insert 'b' at pos 0 → "ba"
            │   │   ├── recur("abc", 2, "ba")
            │   │   │   ├── insert 'c' at pos 0 → "cba"
            │   │   │   ├── insert 'c' at pos 1 → "bca"
            │   │   │   └── insert 'c' at pos 2 → "bac"
            │   └── insert 'b' at pos 1 → "ab"
            │       ├── recur("abc", 2, "ab")
            │       │   ├── insert 'c' at pos 0 → "cab"
            │       │   ├── insert 'c' at pos 1 → "acb"
            │       │   └── insert 'c' at pos 2 → "abc"
    */
    char ch = s[pos];
    for(int i = 0; i <= curr.size(); i ++){
        string next = curr;
        next.insert(i, 1, ch);
        recur(s, pos +1, next);
    }
}

int main(){

    string s;
    /*
        Start with first letter, take the subsequent letter and insert them 
        in all possible positions from left to right.
    */
    
    vector<string> inputs;
    while(cin >> s){ inputs.push_back(s); }

    for(int i = 0; i < inputs.size(); ++i){
        recur(inputs[i], 0, "");
        if(i!= inputs.size()-1)cout << '\n';
    }

    return 0;
}