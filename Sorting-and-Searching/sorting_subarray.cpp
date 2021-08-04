/*

Write a function that takes in an array andreturn two integers, denoting starting and ending indices of the smallest subarray in the input array that needs to be sorted in place so that the entire input is sorted.
If the input array is laready sored, return a pair [-1,-1]

Sample Input
------------
[0,2,4,7,10,11,7,12,13,14,16,19,29]

Sample Output
-------------
[4,6]

*/
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


pair<int,int> subarraySorting(vector<int> arr){
    //Expected Optimal Complexity O(n) Time, O(1) Space
    //may be start with O(NLogN) and try to improve
    //complete this function
    int leftIndex = -1, rightIndex = -1;
    int n = arr.size();
 
    // traverse from left to right and keep track of maximum so far
    int max_so_far = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max_so_far < arr[i]) {
            max_so_far = arr[i];
        }
 
        // find the last position that is less than the maximum so far
        if (arr[i] < max_so_far) {
            rightIndex = i;
        }
    }
 
    // traverse from right to left and keep track of the minimum so far
    int min_so_far = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        if (min_so_far > arr[i]) {
            min_so_far = arr[i];
        }
 
        // find the last position that is more than the minimum so far
        if (arr[i] > min_so_far) {
            leftIndex = i;
        }
    }
    
    return {leftIndex,rightIndex};
}

int main() {
    vector<int> v{1,2,3,4,5,6,7,8,9};
    auto p =subarraySorting(v);
    cout << p.first << " " << p.second << endl;
    return 0;
}