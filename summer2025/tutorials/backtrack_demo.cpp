#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

void clear(){
    cout << "\033[2J\033[1;1H";
}

void printMap(const vector<string>& grid, char flag){
    clear();
    // e represent exploring phase and b represent backtracking phase
    if(flag == 'e') cout << "Exploring..." << '\n';
    else if(flag == 'b') cout << "Backtracking..." << '\n';
    else if(flag == 'd') cout << "We are done!" << '\n';

    for(auto& r : grid){
        cout << r << '\n';
    }

    this_thread::sleep_for(chrono::milliseconds(800));
}

bool backtrack(vector<string> & grid, int r, int c){
    // Base case: out of bounds
    if(r < 0  || r >= grid.size() || c < 0 || c >= grid[0].size()){
        return false;
    }
    // Base case: we reached the end
    if(grid[r][c] == 'e'){
        printMap(grid, 'd');
        return true;
    }
    // Base case: this is not an unvisited cell
    if(grid[r][c] != ' ') return false;

    grid[r][c] = '@'; // current cursor position
    printMap(grid, 'e');
    grid[r][c] = '.'; // mark as visited cell

    vector<pair<int, int>> dir = {{1,0}, {0, 1}, {0, -1}, {-1, 0}};

    for(auto d : dir){
        if(backtrack(grid, r + d.first, c + d.second)) return true;
    }

    // backtracking ...
    grid[r][c] = '@';
    printMap(grid, 'b');
    grid[r][c] = '.';
    return false;
}

int main(){

    vector<string> grid = {
        "#############",
        "# # #   #   #",
        "#   # # # # #",
        "# ### # # # #",
        "#     #   # #",
        "# ##### ### #",
        "#   #   #  e#",
        "#############",
    };
    
    printMap(grid, 's');
    cout << "Start backtrack algorithm?" << '\n';
    int ans; cin >> ans; 
    if(ans) backtrack(grid, 1, 1);

    return 0;
}