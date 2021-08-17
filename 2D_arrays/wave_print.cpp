/*
Given a matrix, print it in Reverse Wave Form

m -> number of rows
n -> number of columns

Input
-----
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Output
------
4 8 12 16 15 11 7 3 2 6 10 14 13 9 5 1
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> WavePrint(int m,int n, vector<vector<int>> arr) {
    
    int wave = 1;
    vector<int> linear_arr;
    for(int j=n-1; j >= 0; j--) {
        if (wave == 1) {
            for (int i = 0; i < m; i++)
                linear_arr.push_back(arr[i][j]);    
            wave = 0;
        } else {
            for (int i = m - 1; i >= 0; i--)
                linear_arr.push_back(arr[i][j]);
            wave = 1;
        }      
    }
    return linear_arr;
}

int main() {
    vector<vector<int>> arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int m = 4; int n = 4;
    vector<int> result = WavePrint(m,n,arr);
    for(auto num: result) {
        cout << num << " ";
    }
    cout << endl;
}