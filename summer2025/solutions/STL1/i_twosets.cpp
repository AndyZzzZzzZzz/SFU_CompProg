#include <iostream>
#include <vector>

using namespace std;

int main(){

    long long n; cin >> n;

    // intuition: division is possible only if total sum is even
    long long total = 0;
    // compute the total sum
    for(long long i = 0; i <= n; i ++) total += i;

    // if total sum is odd, this is not possible
    if(total % 2){
        cout << "NO" << '\n';
        return 0;
    }

    // contruct a target sum for one of the set
    long long targ = total /2;
    vector<long long> set1, set2;

    // greedy select the largest element to put into one set
    for(long long i = n; i > 0; i --){
        // check that we do not go out of bound
        if(targ >= i){
            targ -= i;
            set1.push_back(i);
        }else{
            set2.push_back(i);
        }
    }

    if(targ == 0){
        cout << "YES" << '\n';
        cout << set1.size() << '\n';
        for(auto i : set1) cout << i << ' ';
        cout << '\n' << set2.size() << '\n';
        for(auto i : set2) cout << i << ' ';  
    }else{
        cout << "NO" << endl;
    }

    return 0;
}