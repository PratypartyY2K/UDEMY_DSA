// extension of housing problem

// smallest window that contains the required sum
// handle if you have negative integers in the array

/*
#include <iostream>
#include <limits.h>
using namespace std;

int housing(int *arr, int n, int k) {

    if(k<=0) // if plot's area is 0
        return 0;
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
            return len; // return length as soon as current sum == k
        }
    }

    return len; // return len if required subarray does not exist
}

int main() {

    int plots[] = {1,3,3,1,4,1,3,2,1,1};
    int n = sizeof(plots)/sizeof(int);
    int k = 8;

    int length = housing(plots, n, k);
    cout << length << endl;

    return 0;
}
*/


// logic for handling negative integers
/* 
See for using sliding window, the goal is to make all the elements of the array non negative and then use the technique.

Lets see how we can do it. Lets say the minimum element of the array is a negative integer whose absolute value is X.

If we add X to all elements of the array, there will be no negative integer left. But now sum of every subarray will be changed.

So we have to change the target sum accordingly.

If there are M elements in a subarray and there old sum was S, then the new sum will be S + M*X as for each element X is added to the new sum.

Now we start using the sliding window technique, we make a variable for storing current sum say CS = arr[0].

Now 'i' pointer is on first index, we start 'j' pointer from the second element and add all elements one by one to the CS, and keep incrementing 
target sum by 'X' for each element we add to current sum.

That means target sum keeps changing , and at any instant it is equal to the initial target sum + 'X' * (number of elements whose values we are adding 
in the current sum).

While iterating if our current sum exceeds our current target sum, we subtract the element at arr[i] from the current sum, and subtract 'X' from current 
target sum. While iterating, for any 'i' and 'j' if we get current sum equal to current target sum that gives us the solution.
*/

// handles negative integers

#include <iostream>
#include <limits.h>
using namespace std;

int convert(int *arr, int n) {
    int min = arr[0];
    for(int i=1;i<n;i++) {
        if(arr[i]<min) {
            min = arr[i];
        }
    }
    return min;
}

int housing(int *arr, int n, int k) {

    if(k<=0) // if plot's area is 0
        return 0;
    
    int left = 0; // slow pointer (shrink the window)
    int right = 0; // faster pointer (expand the window)
    int cur_sum = 0; // current sum
    int len = INT_MAX; // stores length of the required subarray
    
    int min = convert(arr, n);
    
    for(int k=0;k<n;k++) {
        arr[k] += min;
    }

    k = k + min*n; 

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
            return len; // return length as soon as current sum == k
        }
    }

    return len; // return len if required subarray does not exist
}

int main() {

    int plots[] = {1,3,-3,1,4,1,-3,2,-1,1};
    int n = sizeof(plots)/sizeof(int);
    int k = 6;

    int length = housing(plots, n, k);
    cout << length << endl;

    return 0;
}