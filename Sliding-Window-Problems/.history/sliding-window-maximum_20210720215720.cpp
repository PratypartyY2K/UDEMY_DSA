/*
Given an array of integers and an integer K, return a vector containing maxiumum for each and every continguos subarray of size k

Constraints:
------------
-10000<=A[i]<=10000, where 0<i<size of array
K>0

Sample Input
------------
K = 3
input = {1,2,3,1,4,5,2,3,6}

Sample Output
-------------
output = {3,3,4,5,5,5,6}
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> maxInWindow(vector<int> input,int k){
    
    vector<int> output; 
    
    if(input.size() < k) {
        return {};
    }
    // 1,2,3,1,4,5,2,3,6
    int i=0;
    int j=k-1;
    int maximum = -1;

    maximum = max(input[0], max(input[1],input[2]));
    output.push_back(maximum);

    while(j < input.size()){
        cout << i << " " << j << endl;
        if(maximum == input[i]){
            maximum = max(input[i+1],max(input[i+2],input[j]));
            output.push_back(maximum);
        }

        else if(input[j]>maximum){
            output.push_back(input[j]);
            maximum = input[j];
        }

        else
            output.push_back(maximum);
        j++;
        i++;

    }
    return output;
}

int main() {
    vector<int> input = {1,2,3,1,4,5,2,3,6};
    int k = 3;
    vector<int> result;
    result = maxInWindow(input, k);
    for(int num=0;num < result.size();num++) {
        cout << result[num] << " ";
    }
    cout << endl;
}