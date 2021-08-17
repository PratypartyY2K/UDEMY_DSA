/*
Given a ladder containing N steps, you take a jump of 1,2 or 3 at each step. Find the number of ways to climd the ladder
*/
#include<iostream>
using namespace std;

//
int countWays(int n){
	//Base
	if(n<0){
		return 0;
	}
	if(n==0){
		return 1;
	}

	//Recursive	
	return countWays(n-1) + countWays(n-2) + countWays(n-3);

}


int main(){
	int n;
	cin>>n;
	cout <<countWays(n) <<endl;

	return 0;
}
// O(3^N) time complexity
// can be optimized using DP
