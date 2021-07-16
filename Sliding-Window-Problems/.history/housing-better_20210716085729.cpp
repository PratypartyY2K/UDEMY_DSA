// extension of housing problem

// smallest window that contains the required sum
// handle if you have negative integers in the array

#include <iostream>
#include <limits.h>
using namespace std;

void housing(int *arr, int n, int k) {

    int left = 0; // slow pointer (shrink the window)
    int right = 0; // faster pointer (expand the window)
    int cur_sum = 0; // current sum
    int len = INT_MAX; // stores length of the required subarray
    while(right < n) { // pointer should not go out_of_bounds

        cur_sum += arr[right]; // add element with index right to current sum
        right++; // shift the right pointer by 1 index

        while(cur_sum > k and left < right) {
            
            // update the result if the current window's length is less than the
            // minimum found so far
            len = min(len, right-left-1);

            // remove elements from the window's left side till the window
            // becomes stable again
            cur_sum = cur_sum - arr[left];
            left++;
        }

        if(cur_sum == k) {
            // print window and its length
            cout << left << "-" << right << "=" << len << endl;
        }
    }

    return;
}

int main() {

    int plots[] = {1,3,2,1,4,1,3,2,1,1};
    int n = sizeof(plots)/sizeof(int);
    int k = 8;

    housing(plots, n, k);

    return 0;
}