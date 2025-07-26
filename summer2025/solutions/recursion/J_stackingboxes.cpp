#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to check if box a can nest in box b (strictly less for all dims)
bool can_nest(const vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < a.size(); ++i)
        if (a[i] >= b[i]) return false;
    return true;
}

// Recursive function to compute the longest chain from box at pos
int recur(int pos, const vector<vector<int>>& boxes, vector<int>& memo, vector<int>& parent) {
    // Base case, we've computed the result previously
    if (memo[pos] != -1) return memo[pos];

    int best = 1;
    int best_next = -1;

    // Attempt to track all chains and their length
    for (int i = 0; i < boxes.size(); ++i) {
        // If we detect a fitting box, try to go deeper
        if (can_nest(boxes[pos], boxes[i])) {
            int candidate = 1 + recur(i, boxes, memo, parent);
            if (candidate > best) {
                best = candidate;
                best_next = i;
            }
        }
    }
    // track the parent of previous call so we can form the indices chain
    parent[pos] = best_next;
    // Cache the result
    memo[pos] = best;
    return best;
}

int main() {
    int num_boxes, dimension;
    while (cin >> num_boxes >> dimension) {
        vector<vector<int>> boxes(num_boxes, vector<int>(dimension));
        for (int i = 0; i < num_boxes; ++i) {
            for (int j = 0; j < dimension; ++j)
                cin >> boxes[i][j];
            // sort individual boxes so the rotation logic is considered
            sort(boxes[i].begin(), boxes[i].end()); 
        }

        // Store original indices for output
        vector<int> original_idx(num_boxes);
        for (int i = 0; i < num_boxes; ++i) original_idx[i] = i + 1;

        // Sort both boxes and indices together
        for (int i = 0; i < num_boxes; ++i) {
            for (int j = i + 1; j < num_boxes; ++j) {
                if (boxes[i] > boxes[j]) {
                    swap(boxes[i], boxes[j]);
                    swap(original_idx[i], original_idx[j]);
                }
            }
        }

        // Memoization for caching
        vector<int> memo(num_boxes, -1);
        // Track the parent of indices to we can form chain
        vector<int> parent(num_boxes, -1);

        int max_chain = 0, start_idx = 0;
        for (int i = 0; i < num_boxes; ++i) {
            int length = recur(i, boxes, memo, parent);
            if (length > max_chain) {
                max_chain = length;
                start_idx = i;
            }
        }

        // Output
        cout << max_chain << endl;

        // Recover chain
        vector<int> answer;
        int curr = start_idx;
        while (curr != -1) {
            answer.push_back(original_idx[curr]);
            curr = parent[curr];
        }
        for (int i = 0; i < answer.size(); ++i) {
            cout << answer[i];
            if (i != answer.size() - 1) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}