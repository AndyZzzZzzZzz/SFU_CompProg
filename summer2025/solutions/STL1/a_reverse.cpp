#include <iostream>
#include <stack>

using namespace std;

int main(){

    // use a stack: first in last out
    stack<int> stk;

    // read in values
    int N; cin >> N;
    for(int i = 0; i < N; i ++){
        int t; cin >> t;
        stk.push(t);
    }


    // while stack is not empty, retrieve the element from top of the stack
    while(!stk.empty()){
        cout << stk.top() << '\n';
        stk.pop();
    }
    return 0;
}