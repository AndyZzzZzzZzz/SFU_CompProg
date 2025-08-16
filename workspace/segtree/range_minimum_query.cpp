#include <iostream>
#include <vector>

using namespace std;

// build the segmentation tree with node storing minimal between intervals
class SegTree {
    vector<int> tree;
    int size;

    public:
	    SegTree(vector<int>& A) {
            size = A.size();
            tree.resize(2*size, INT_MAX);
            _build(0, 0, A.size()-1, A);
        };
        
        void update(int index, int val){
            _update(0, 0, size-1, index-1, val);
        }

        int query(int left, int right){
           return _query(0, 0, size-1, left-1, right-1);
        }

    private:
        void _build(int node, int start, int end, vector<int> & A){
            if(start == end){
                // Leaf node always stores single element
                tree[node] = A[start];
            }else{
                int mid = (start + end)/2;
                // recursively traverse left and right child
                _build(2*node+1, start, mid, A);
                _build(2*node +2, mid + 1, end, A);
                // internal node stores the minimal of its two childs
                tree[node] = min(tree[2*node+1], tree[2*node +2]);
            }

        }

        void _update(int node, int start, int end, int idx, int val){
            if(start == end){
                // Update the corresponding leaf node
                tree[node] =  val;
            }else{
                int mid = (start + end)/2;
                if(start <= idx && idx <= mid){
                    _update(2*node+1, start, mid, idx, val);
                }else{
                    _update(2*node+2, mid+1, end, idx, val);
                }
                // update again after the change
                tree[node] = min(tree[2*node+1], tree[2*node+2]);
            }
        }

        int _query(int node, int start, int end, int l, int r){
            // If completely out of range, return invalid (not happening in this problem)
            if(r < start || end < l) return INT_MAX;
            // Within range, return value stored
            else if(l <= start && end <= r) return tree[node];

            int mid = (start + end)/2;
            int p1 = _query(2*node+1, start, mid, l, r);
            int p2 = _query(2*node +2, mid +1, end, l, r);

            return min(p1, p2);
        }
};

int main() {
    
    int len, tests; cin >> len >> tests;
    vector<int> A(len, 0);

    for(int i = 0; i < len; ++i){
        cin >> A[i];
    }
    // build the tree
    SegTree tree(A);

    while(tests--){
        char type;
        int l, r;
        cin >> type >> l >> r;
        
        if(type == 'u') tree.update(l, r);
        else cout << tree.query(l, r) << '\n';
    }

}