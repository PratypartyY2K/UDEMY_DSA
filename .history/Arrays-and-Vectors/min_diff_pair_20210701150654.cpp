#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// Brute Force Approach O(N^2)
/* 
pair<int,int> minDifference(vector<int> a,vector<int> b){
    //Complete this method
    int n = a.size(); //length of first array
    int m = b.size(); //length of second array
    
    pair<int,int> res;
    int min_diff = INT_MAX; // minimum difference
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(abs(a[i]-b[j])<min_diff) {
                min_diff = abs(a[i]-b[j]);
                res.first = a[i];
                res.second = b[j];
            }
        }
    }
    return res;
}
*/
// O(nlogn) + O(n) time complexity
pair<int,int> minDifference(vector<int> a,vector<int> b){
    //Complete this method
    int n = a.size();
    int m = b.size();
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    pair<int, int> res;
    
    int min_diff = INT_MAX;
    
    int i=0, j=0;
    while(i<n and j<m) {
        if(min_diff > abs(a[i]-b[j])) {
            min_diff = abs(a[i]-b[j]);
            res.first = a[i];
            res.second = b[j];
        }
        if(a[i]<b[j]) {
            i++;
        } else {
            j++;
        }
    }
    return res;
}

int main() {
    
    vector<int> a{23,5,10,17,30};
    vector<int> b{26,134,135,14,19};
    auto result = minDifference(a,b);
    cout << result.first << "," << result.second << endl;
    
    return 0;
}