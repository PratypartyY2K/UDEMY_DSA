#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

/*
vector<int> subarraySort(vector<int> a) {
    
    //brute (NlogN Time + O(logN) space)
    vector<int> b(a);
    sort(a.begin(), a.end());

    //do comparision
    int i = 0; //comparision pointer for left index
    int n = a.size();
    while(i<n and a[i]==b[i]) {
        i++;
    }
    int j = a.size()-1; //comparision pointer for right index
    while(j>=0 and a[j]==b[j]) {
        j--;
    }

    //already sorted
    if(i==a.size()) {
        return {-1,-1};
    }
    return {i,j};
}
*/

// if next element is smaller than the previous element, then it is out of order
bool outOfOrder(vector<int> arr, int i) {
    int x = arr[i];
    // if x = arr[0], then if next element (arr[1]) is > arr[0], arr[0] is out of order
    if(i==0) {
        return x > arr[1];
    }
    //if nth element is less than (n-1)th element, then nth element is out of order.
    if(i==arr.size()-1) {
        return x < arr[i-1];
    }
    return x > arr[i+1] or x < arr[i-1];
}

pair<int, int> subArraySort (vector<int> arr) {

    int smallest = INT_MAX;
    int largest = INT_MIN;
    for(int i=0;i<arr.size();i++) {
        int x = arr[i];

        if(outOfOrder(arr,i)) {
            smallest = min(smallest,x);
            largest = max(largest,x);
        }
    }

    //next step find the right index where smallest and largest lie (subarray) for out solution
    if(smallest == INT_MAX) {
        return {-1,-1};
    }

    int left = 0;
    while(smallest >= arr[left]) {
        left++;
    }
    int right = arr.size()-1;
    while(largest <= arr[right]) {
        right--;
    }

    return {left, right};
}

int main() {

    vector<int> arr = {1,2,3,4,5,8,6,7,9,10,11};
    auto p = subArraySort(arr);
    cout << p.first << " and " << p.second << endl;

    return 0; 
}