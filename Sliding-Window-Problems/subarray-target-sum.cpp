#include<bits/stdc++.h>
using namespace std;

int cntSubarrays(vector<int> arr,int k){
    int n = arr.size();
    
    unordered_map<int, int> prevSum;
 
    int res = 0; //number of subarrays
 
    // Sum of elements so far.
    int currsum = 0;
 
    for (int i = 0; i < n; i++) {
 
        currsum += arr[i];
 
        if (currsum == k)
            res++;
 
        if (prevSum.find(currsum - k) != prevSum.end())
            res += (prevSum[currsum - k]);
 
        prevSum[currsum]++;
    }
    return res;
}

int main() {
    vector<int> input = {10, 2, -2, -20, 10 };
    int k = -10;
    int result = cntSubarrays(input, k);
    cout <<  result << endl;
}