#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set> //hash set
#include <map>
#include <unordered_map> // hash map 
#include <algorithm>
#include <numeric>

using namespace std;

// Vector is a dynamic array in C++
void vector_example(vector<int> & v, int element){

    // add an element into vector
    v.push_back(element);
    // remove element from the end of the vector 
    v.pop_back();

    // STL algorithms
    // sorting elements into the vector
    // 0, 1 .. 99, 100
    sort(v.begin(), v.end());

    // remove a particular element
    // find returns the first position a particular element appearing if it doesn exist, return -1
    // erase removes an element from index 
    v.erase(find(v.begin(), v.end(), 6));
}

// Stack 
// Conatiner that follows first in last out property
/*
    input stream -> 1 3 8 6 2
    stack looks like:    
                        6 - top 
                        8
                        3
                        1 - bottom 
*/
void stack_example(){

        stack<int> my_stack;
        int e = 10;
        // put elements into the stack (on top the stack)
        my_stack.push(10);
        // check the size of the stack
        int size = my_stack.size();
        // check if stack is empty
        bool is_empty = my_stack.empty();
        // retrieve the top of the stack
        int top_element = my_stack.top();
        // remove element
        my_stack.pop();

}

// Queue
// follows first in first out principle
/*
    Example: input stream: 1 -> 8 -> 36 .. 2  ..  0
    Queue:      1        8      36 ..       2  ...      0
            front                                       back

*/
void queue_example(){

    // declare a queue
    queue<int> my_queue;
    int e = 10;

    // put an element inside a queue
    my_queue.push(e);
    // access the front of the queue
    int f = my_queue.front();
    // remove the front element
    my_queue.pop();
    
    my_queue.empty();
    my_queue.size();

}

// Set
// Container for unique elements
/*
 Input stream: 1 -> 6 -> 88 .. 88 -> 2 -> 9

 Set will conatin: {1, 6, 88, 2, 9}
*/
void set_example(){

    set<int> my_set;
    unordered_set<int> hash_set;
    int e = 10;

    // put elements into the set
    // log(N): {1, 6, 88, 2, 9}
    // {1, 2, 6, 9, 88}
    //   data comes in this order {1, 6, 88, 2, 9}
    /*
                        1
                            6
                         2     88
                             9
    
    */                  
    my_set.insert(e); // ordered_set
    hash_set.insert(e); // hash set O(1)

    // remove element from the set 
    hash_set.erase(e);

    hash_set.empty();
    hash_set.size();

    // Find an element in a set
    int target = 2;
    if(hash_set.find(target) != hash_set.end()){
        //do something
    }

    // iterate through a set
    for(auto element : my_set){}

}

// Map
// key value pairs
/*
    Example map
            id                  names
            1          ->          bob, jason
            2          ->           v, m, n
            3          ->            anne
            4          ->               k

*/
void map_example(){

    unordered_map<int, vector<string>> my_map;

    unordered_map<int, int> counting;

    int id = 0;
    // count the frequencies of id appearing
    counting[id] ++;

    // put something in map
    string name = "Andy";
    my_map[id].push_back(name);

    // Standard operations
    my_map.size();
    my_map.empty();

    // find particular element
    int target = 9;
    if(counting.find(target) != counting.end()){
        // do something
    }

    // iterating
    for(auto x : counting){
        // x is a pair <val1, val2>
        // get key
        x.first;
        // get val
        x.second;
    }

}

// STL Algorithm (USEFUL)
void stl_alg_example(){

    int n = 10;
    vector<int> v(n);

    // reverse all elements in-place
    reverse(v.begin(), v.end());

    // sorting elements in-place
    // sorting index 4 to 9
    sort(v.begin() + 4, v.end());

    // fill elements in array
    fill(v.begin(), v.end(), 4);

    vector<int> rev_v(n);
    // swap two elements or anything?
    // 1 2 3 4 5 
    // 2 1 3 4 5 
    swap(v[0], v[1]);
    swap(v, rev_v);
    
    // finding the sum of vector (without a loop)
    int sum = std::accumulate(v.begin(), v.end(), 0);

    // finding max and/or min elements
    // int a[10];
    int min_e = *min_element(v.begin(), v.end());
    
}

int main(){


    return 0;
}