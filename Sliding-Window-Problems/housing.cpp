// Housing

/*
Along one side if a road there is a sequence of vacant plots of land.
Each plot has a different area (non-zero). So, the areas form a sequence A[1], A[2],....., A[N].

You want to buy K acres of land to build a house.
You want to find all segments of continguos plots (i.e., subseciton in the sequence) of whose sum is exactly K

Sample Input
------------
Plots = [1,3,2,1,4,1,3,2,1,1,2]
K=8

Sample Output
-------------
2 5
4 6
5 9
*/
#include <iostream>
using namespace std;

void housing(int *arr, int n, int k) {

    int i=0;
    int j=0;
    int cs=0; // current_sum

    while(j<n) {
        
        // expand to the right
        cs += arr[j];
        j++;

        // remove elements from the left till cs > k and i < j
        while(cs>k and i<j) {
            cs = cs - arr[i];
            i++;
        }

        // check if at any given point current sum is equal to target (k)
        if(cs == k) {
            // print the window
            cout << i << "-" << j-1 << endl; // we are taking j-1 as j++ has caused the right pointer to move one step ahead before cs == k
        }
    }

    return;
}

int main() {

    int plots[] = {1,3,2,1,4,1,3,2,1,1};
    int n = sizeof(plots)/sizeof(int);
    int k=8;

    housing(plots,n,k);

    return 0;
}