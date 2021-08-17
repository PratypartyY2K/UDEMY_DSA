/* 
Staircase search
----------------

Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it. Otherwise, print “Not Found”. In the given matrix, every row and column is sorted in increasing order. The designed algorithm should have linear time complexity.

Input: mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
              x = 29
Output: Found at (2, 1)
*/
#include<iostream>
using namespace std;


pair<int,int> staircaseSearch(int arr[][4],int n,int m,int key){

    //later if the element is not present return {-1,-1}
    
    if(key < arr[0][0] or key>arr[n-1][m-1]){
        return {-1,-1};
    }

    //staircase search
    int i=0;
    int j = m-1;

    while(i<=n-1 and j>=0){

        if(arr[i][j]==key){
            return {i,j};
        }
        else if(arr[i][j]>key){
            j--;
        }
        else{
            i++;
        }
    }
    return {-1,-1};
}


int main(){

	//2D Row & Column Wise Sorted Array
	int arr[][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
    int n = 4,m=4; 
    pair<int,int> coords = staircaseSearch(arr,n,m,27);
    cout<< coords.first<<" "<<coords.second <<endl;
	return 0;
}