// O)n^3) solution
/*
// Including climits, which allows for usage of INT_MIN constant in C++
#include <climits>

class Solution {
  public:
    int maxContiguousSubarraySum(vector<int>& nums) {
      int n = nums.size();
      int maximumSubArraySum = INT_MIN;
  
      /*
        We will use these outer 2 for loops to investigate all
        windows of the array.
        
        We plant at each 'left' value and explore every
        'right' value from that 'left' planting.
  
        These are our bounds for the window we will investigate.
      */
     /*
      for (int left = 0; left < n; left++) {
        for (int right = left; right < n; right++) {
          // Let's investigate this window
          int windowSum = 0;
  
          // Add all items in the window
          for (int k = left; k <= right; k++) {
            windowSum += nums[k];
          }
  
          // Did we beat the best sum seen so far?
          maximumSubArraySum = max(maximumSubArraySum, windowSum);
        }
      }
  
      return maximumSubArraySum;
    }
};
*/

// O(n^2) solution
/*
// Including climits, which allows for usage of INT_MIN constant in C++
#include <climits>

class Solution {
  public:
    int maxContiguousSubarraySum(vector<int>& nums) {
      int n = nums.size();

      // Initialise the variable with minimum integer value
      int maximumSubArraySum = INT_MIN;

      // Left will be the starting index of subarray
      for (int left = 0; left < n; left++) {
        int runningWindowSum = 0;

        // Right will be the ending index of subarray
        for (int right = left; right < n; right++) {

          // Add the current element to previous computed value
          // To get the subarray sum
          runningWindowSum += nums[right];
  
          // Does this window beat the best sum we have seen so far?
          maximumSubArraySum = max(maximumSubArraySum, runningWindowSum);
        }
      }
  
      return maximumSubArraySum;
    }
};
*/
#include<iostream>
#include<vector>
using namespace std;

// Dynamic Programming paradigm (takes into account if array has all negative elements)

/*int maxSubarraySum(vector<int> arr){
    //Complete this function, your function should return the maximum subarray sum
    int n = arr.size();
    
    int max_current = arr[0];
    int max_global = arr[0];
    
    for(int i=1;i<n;i++) { //i starts from 1 because max_current and max_global have already been assignmed arr[0]
        
        max_current = max(arr[i], max_current+arr[i]);
        
        if(max_current>max_global) {
            max_global=max_current;
        }
    }
    return max_global;
}*/

// Return 0 if all elements of the array are negative

int maxSubarraySum(vector<int> arr){
    //Complete this function, your function should return the maximum subarray sum
    int n = arr.size();
    int max_current=0; int max_global=0;
    
    for(int i=0;i<n;i++) {
        max_current += arr[i];
        
        if(max_current > max_global) {
            max_global = max_current;
        }
        
        if(max_current < 0) {
            max_current = 0;
        }
    }
    return max_global;
}

int main() {
    vector<int> arr{-5, -2, -2, -1, -6, -8};
    cout << maxSubarraySum(arr) << endl;
    return 0;
}