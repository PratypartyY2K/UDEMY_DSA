/*
Given two non-empty arrays, find the pair of numbers (one from each array) whose absolute difference is minimum. Print the any one pair with the smallest difference

Sample Input
------------
a1=[-1,5,10,20,3]
a2=[26,134,135,15,17]

Sample Output
-------------
[20,17]
*/
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

void min_pair(vector<int> a1, vector<int> a2) {
    int min_diff = INT_MAX;
    pair<int,int> res;
    int m = a1.size();
    int n = a2.size();
    int curr_diff;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            curr_diff = abs(a1[i] - a2[j]);
            if(curr_diff<min_diff) {
                min_diff = curr_diff;
                res.first = a1[i];
                res.second = a2[j];
            }
        }
    }
    cout << "[" << res.first << "," << res.second << "]" << endl;
}

int main() {
    vector<int> a1 = {-1,5,10,20,3};
    vector<int> a2 = {26,134,135,15,17};
    min_pair(a1,a2);

    return 0;
}