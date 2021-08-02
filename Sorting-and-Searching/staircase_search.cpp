/*
https://leetcode.com/problems/search-a-2d-matrix/
*/

#include <bits/stdc++.h>
using namespace std;

/* 
m -> number of columns
n -> number of rows
vector<vector<int>> v => matrix (MxN)
K -> integer to find
*/

// Brute force
/*
pair<int,int> search(int m, int n, vector<vector<int>> v, int k) {
    // write your code here
    pair<int, int> res;
    if(m == 0 || n == 0)
        return {};

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if (v[i][j] == k) {
                res.first = i;
                res.second = j;
            }
        }
    }
    return res;
}
*/

pair<int, int> search(int m, int n, vector<vector<int>> v, int k) {
    
    if( m == 0 || n == 0) return {};
    
    pair<int,int> res;

    int smallest = v[0][0], largest = v[m - 1][n - 1];

    int i = 0, j = n - 1;
    while (i < m && j >= 0)
    {
        if (v[i][j] == k)
        {
            res.first = i;
            res.second = j;
            return res;
        }
        if (v[i][j] > k)
            j--;
       
        // Check if mat[i][j] < x
        else
            i++;
    }

    return res;
}

int main() {
    
    vector<vector<int>> v = { 
                                { 10, 20, 30, 40 },
                                { 15, 25, 35, 45 },
                                { 27, 29, 37, 48 },
                                { 32, 33, 39, 50 },
                                { 11, 17, 21, 23 }
                            };
    int k = 29;
    auto res = search(5,4,v,29);
    cout << res.first << "," << res.second << "\n";

    return 0;
}