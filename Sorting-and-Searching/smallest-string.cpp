/*
You are given a list of n strings a1,a2,....,an. You would like to concatenate them aogether in some order such that the resulting string would be lexicographically smallesy. Given the list of strings, output the lexicographically smallest concatenation.

Input
-----
3
c
cb
cba

Output
------
cbacbc


Input
-----
3
a
ab
aba

Output
------
aabaab
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool compare(string x, string y) {
    return x+y < y+x;
}

int main() {
    
    string arr[] = {"a","ab","aba"};
    int n = 3;
    
    sort(arr, arr+n, compare);
    
    for(auto s: arr) {
        cout << s;
    }

    return 0;
}