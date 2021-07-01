#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<vector<int> > triplets(vector<int> arr, int sum) {
    //Logic
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int> > result;

    //Pick every a[i], pair sum for remaining part
    for(int i=0;i<n-3;i++) {
        int j=i+1;
        int k = n-1;

        //two pointer approach
        //j moves forward and k moves backward
        while(j<k) {
            int current_sum = arr[i];
            current_sum += arr[j];
            current_sum += arr[k];

            if(current_sum == sum) { //check if the current sum is equal to the target sum
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            }
            else if (current_sum > sum) { // we need to decrease the current sum
            // Hence, we move the k pointer one step back (sorted array)
                k--;
            }
            else {
                j++;
            }
        }
    }
    return result;
}

int main() {
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int S = 18;

    auto result = triplets(arr,S);
    
    for(auto v : result) {
        for(auto n: v) {
            cout << n << ",";
        }
        cout << endl;
    }

    return 0;
}