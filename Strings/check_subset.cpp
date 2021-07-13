// Given two non-empty strings, write a funciton tht determines whether the second string is a subsequence of first one

/*

Sample Input
------------
codingminutes
cines

Sample Output
-------------
Yes

*/

#include <bits/stdc++.h>
using namespace std;

bool checkSubsq(string str, string substr) {

    int ptr = 0;
    
    if(substr.size()> str.size()) {
        return false;
    }

    int i = str.length() - 1; //bigger string
	int j = substr.length()-1; // larger string

	while(i>=0 and j>=0){ 
		if(substr[j]==str[i]){
            //move both the pointers backwards if the letters match
			i--;
			j--;
		}
		else{ //otherwise only move the bigger string's pointer back by 1
			i--;
		}
	}
	if(j==-1){
		return true; // all the letters of the substring are matched
	}
	return false;
}

int main() {
    
    string str, substr;
    cin >> str >> substr;

    if(checkSubsq(str, substr)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}