/*
Given an array containing balls of Red, Blue and Green color in a random order.
Your goal is to arrange these balls insorted order - Red Balls, followed by Blue and then Green Balls.

Red balls -> 0
Blue -> 1
Green -> 2

Similar to "DNF Algorithm"

Input
-----
{0,0,1,2,0,1,2,0}

Output
------
{0,0,0,0,1,1,2,2}
*/
#include <iostream>
#include <vector>
using namespace std;


vector<int> sortBalls(vector<int> &balls){
    //sort the balls in place in a single pass (O(N) time, O(1) space)
    
    int n=balls.size();
    int low=0;
    int mid=0;
    int high=n-1;
    while( mid <= high){
        switch(balls[mid]){
            case 0:
                swap(balls[low++] , balls[mid++]);
                break;
            case 2:
                swap(balls[mid] , balls[high--]);
                break;
            default:mid++;
            break;
        }
 
    }   
    return balls;
}

int main() {
    
    vector<int> v{1,0,1,2,0,1,2,0};
    sortBalls(v);
    for(auto x: v){ 
        cout << x << " ";
    }
    cout << endl;

    return 0;
}