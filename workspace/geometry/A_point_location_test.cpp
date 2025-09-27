#include <iostream>

using namespace std;

int main(){

    int n; cin >> n;
    double x1, y1, x2, y2, px, py;
    while(n --){
        cin >> x1 >> y1 >> x2 >> y2 >> px >> py;

        double res = ((px - x1)*(y2 - y1)) - ((py - y1)*(x2 - x1));

        if(res == 0) cout << "TOUCH" << '\n';
        else if(res > 0) cout << "RIGHT" << '\n';
        else cout << "LEFT" << '\n';
    }
    return 0;
}