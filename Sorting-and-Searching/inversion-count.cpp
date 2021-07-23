/*
Given an array containing integers, you need to count the total number of inversions.

 Inversion => Two elements a[i] and a[j] form an inversion of a[i]>a[j] and i<j

 Sample Input
 ------------
 [0,5,2,3,1]

 Sample Output
 -------------
 5
 */
#include <bits/stdc++.h>
using namespace std;

/* Brute force O(n^2)

int countInversion(vector<int> arr) {
    int count=0;
    int n = arr.size();
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[i]>arr[j]) {
                count++;
            }
            
        }
    }
    return count;
}
*/

int merge(vector<int> &arr, int s, int e) {
    int i = s;
    int m = (s+e)/2;
    int j = m+1;

    vector<int> temp;
    int count = 0;
    while(i<=m and j<=e) {
        if(arr[i]<arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            count += m-i+1;
            temp.push_back(arr[j]);
            j++;
        }
    }

    // if arrays get exhausted

    // copy remaining elements from first array
    while(i<=m) {
        temp.push_back(arr[i++]);
    }

    // or copy remaining elements from second array
    while(j<=e) {
        temp.push_back(arr[j++]);
    }

    //copy back the elements from second array
    int k = 0;
    for(int idx = s;idx <= e; idx++) {
        arr[idx] = temp[k++];
    }

    return count;
 
}
int countInversion(vector<int> &arr, int s, int e) {
    // base case
    if(s>=e) {
        return 0;
    }
    //rec case
    int mid = (s+e)/2;
    int C1 = countInversion(arr,s,mid);
    int C2 = countInversion(arr, mid+1, e);
    int CI = merge(arr,s,e);
    return C1 + C2 + CI;
}

int main() {
    vector<int> arr{0,5,2,3,1};
    int s = 0;
    int e = arr.size()-1;
    cout << countInversion(arr,s,e) << endl;
    return 0;
}