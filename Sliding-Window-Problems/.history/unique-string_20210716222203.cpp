// Unique Substring

/*
Given a string, write a function to find the largest substring with unique characters (no duplicates)

Sample Input
------------
prateekbhaiya
aabcb

Sample Output
-------------
ekbhaiya
abc
*/

// brute-force method, where we find each string and then compare.

#include <bits/stdc++.h>
using namespace std;

string unique_substring(string str){

	int i = 0;
	int j = 0;

	int window_len = 0;
	int max_window_len = 0;
	int start_window = -1;


	unordered_map<char,int> m;


	while(j < str.length()){

		char ch = str[j];

		//if it is inside hashmap & its idx >= start of the current window
		if(m.count(ch) and m[ch]>=i){
			//later on..
			i = m[ch] + 1;
			window_len = j - i; //updated remaining window len excluding current char
		}

		//update the last occ 
		m[ch] = j;
		window_len++;
		j++;

		//update max_window_len at every step
		if(window_len > max_window_len){
			max_window_len = window_len;
			start_window = i;
		}
	}
	return str.substr(start_window,max_window_len);
}


int main(){

	string input;
	cin>>input;

	cout << unique_substring(input) << endl;


	return 0;
}