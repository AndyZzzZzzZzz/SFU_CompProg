#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(){

    string s;
    getline(cin, s);
    // use a set to track unique words
    unordered_set<string> st;

    // track the starting index of words
    int start = 0;
    // boolean flag to track duplicate
    bool flag = true;

    for(int i = 0; i < s.length() + 1; i ++){
        // if we encnter a space or the end of the line
        if(i == s.length() || s[i] == ' '){
            // grab the substring before space (previous word)
            string prev_word = s.substr(start, i - start);
            if(st.find(prev_word) != st.end()){
                flag = false;
                break;
            }
            st.insert(prev_word);
            // update starting index to current string's start
            start = i + 1;
        }
    }

    if(flag) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}