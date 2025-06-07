// reading and outputing data
#include <iostream>
// c++ library for dynamic array
#include <vector>

#include <string>

// replit.com

// get rid of std 
using namespace std;

int main(){
    
    cout << "This is my first program" << endl; //  '\n' is equivalent to endl
    // fun fact: '\n' is faster than endl

    /*
        reading inputs
    */
    int single_element;
    cin >> single_element;
    cout << single_element << '\n';

    // multiple elements
    int e1, e2;
    cin >> e1 >> e2;
    cout << e1 << ' ' << e2 << '\n';

    // read array of elements
    int size; cin >> size;
    vector<int> myarray(size);
    for(int i = 0; i < size; i ++){
        cin >> myarray[i];
    }

    // common pattern 2
    int number_of_testcases; cin >> number_of_testcases;

    while(number_of_testcases--){
        int test;
        cin >> test;
        // solve begins
    }
    
    // read a line of string
    string line;
    getline(cin, line);
    cout << line << endl;

    /*
        string manipulation stuff
    */
    // string concatenation
    string a = "hello";
    string b = "world";
    string c = a + ' ' + b; // -> "hello world"

    // string length
    int length = c.length(); // or c.size()  fun fact: .size() includes this '\0' (end of line character)

    // substring in c++
    string s = "abcdefg";
    string sub = s.substr(2,3); // -> cde

    // find positions of subrting
    int pos = s.find("abc");
    if(pos != string::npos){ // string::npos == -1
        // run your algorithm
    }

    // remove characters
    s.erase(2, 3); // remove 3 characters starting at index 2 

    // insert into string
    s.insert(2, "LOL"); // (position I want to insert, the actual string)

    // default reverse
    reverse(s.begin(), s.end());

    // default sorting
    sort(s.begin(), s.end()); // sort the characters ASCII value


    // Comparison
    string p = "aaabc";
    string z = "aabbs";
    if(s == p){} // return true: string comparison
    if(z < p){} // comapares the ASCII value of the string, from left to right
    // get the ASCII value
    char test0 = 'b';
    char test1 = test0 - 'a';
    cout << test1 << endl; // this will results in 
    // 'a' - 'a' = 0


    return 0;
}