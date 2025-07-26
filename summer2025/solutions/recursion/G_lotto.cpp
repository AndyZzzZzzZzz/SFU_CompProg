#include <iostream>
#include <vector>

using namespace std;

/*
    This is a permutation problem, the key insight is to remove one number each turn
    from right to left
*/
void recur(vector<int> & v, vector<int>& tmp, int pos){
    
    // Base case: if we captured 6 number, print the result
    if(tmp.size() == 6){
        for(int i = 0; i < 6; i ++){
            cout << tmp[i];
            if(i != 5) cout << ' ';
        }
        cout << endl;
        return;
    }
    
    // Backtracking case: 
    for(int i = pos; i < v.size(); ++i){
        /*
            Recursive call stack looks like:
            [1, recur()]
            [1, 2, recur()]
            [1, 2, 3, recur()] ...
            [1, 2, 3, 4, 5, 6] base -> pop back
            [1, 2, 3, 4, 5, 7] base -> pop back -> return to previous call stack
            [1, 2, 3, 4] -> i at 6 right now ...
        */
        tmp.push_back(v[i]);
        recur(v, tmp, i + 1);
        tmp.pop_back();
    }

}

int main(){

    int n, count = 0;
    while(cin >> n && n){
        
        vector<int> curr(n), tmp;

        for(int i = 0; i < n; i ++){
            cin >> curr[i];
        }
        
        if(count) cout <<endl;
        recur(curr, tmp, 0);
        count ++;
    }

    return 0;
}
