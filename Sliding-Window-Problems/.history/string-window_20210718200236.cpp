/*
Given two strings, one big string and one small string, find the 'smallest window' in the big string that contains all characters of the small string.
- Window can have additional characters than required.
- If small string has duplicated, then those duplicates must be present with same or higher count in window.

Input:
------
s1 = hello_world
s2 = lol

Output:
-------
llo
----------------------

Input:
------
s1=fizzbuzz
s2=fuzz

Output:
-------
fizzbu
*/
#include<iostream>
#include<climits>
#include<string>
using namespace std;

string find_window(string s,string p){ // s -> string, p -> pattern


	//Array as a Freq Map or you can hashmap
	int FP[256] = {0}; // for the pattern
	int FS[256] = {0}; // for the string

	for(int i=0;i<p.length();i++){
		FP[p[i]]++;
	}

	//Sliding Window Algorithm
	int cnt = 0;
	int start = 0; // left contraction (starting point of window    )
	int start_idx = -1; //start_idx for best window
	int min_so_far = INT_MAX; // large number
	int window_size;


	for(int i=0 ; i < s.length(); i++){
		//expand the window by including current character
		char ch = s[i];
		FS[ch]++;

		// Count how many characters have been matched till now (string and pattern)
		if(FP[ch]!=0 and FS[ch]<= FP[ch]){
            
            // FP[ch]!=0 => in order to increase the count, the current character needs to be present in the pattern
            // Frequency inside the string should be less than equal to frequency inside the pattern
			cnt += 1;
		}

		//another thing 
		//if all characters of the pattern are found in the current window then you can start contracting
		if(cnt==p.length()){

			//start contracting from the left to remove unwanted characters 
			
			while(FP[s[start]]==0 or FS[s[start]] > FP[s[start]]){

                // FP[s[start]] -> not present in pattern (frequency of current element in window is 0 in the pattern)
                // FS[s[start]] > FP[s[start]] -> frequency of current element in window is greater than frequency of that element in the pattern

				FS[s[start]]--;
				start++;
			}

			//note. the window size
			window_size = i - start + 1; // window size is from start till i
			if(window_size < min_so_far){
				min_so_far = window_size;
				start_idx = start;
			}

		}

	}
	if(start_idx==-1){
		return "No window found";
	}
	return s.substr(start_idx,min_so_far);
}



int main(){

	string s,p;
	cin>>s>>p;


    cout<<find_window(s,p)<<endl;



	return 0;
}