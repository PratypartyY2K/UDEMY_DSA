// You are given a string, you need to print all subsequences of the string sorted by length nd lexicographic sorted order if length is same.

/*

Sample Input
------------
abcd

Sample Output
-------------
,a,b,c,d,ab,ac,ad,bc,bd,cd,abc,abd,acd,bcd,abcd

*/

#include <iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

//sorted subsequences
void subsequence(string s,string o, vector<string> &v){
	//base case
	if(s.size()==0){ // base case if null string
		v.push_back(o);
		return;
	}

	//rec case
	char ch = s[0];
	string reduced_input = s.substr(1);

	//includes
	subsequence(reduced_input, o + ch, v); // include the character

	//excludes
	subsequence(reduced_input, o , v); //exclude the character
}

bool compare(string s1,string s2){
	if(s1.length()==s2.length()){ 
		return s1 < s2; // if length is equal, then sort on the basis of lexicographical order
	}
	return s1.length() < s2.length(); // sort on the basis of length

}

int main(){

	string s;
	cin>>s;

	vector<string> v; // stores all the subsequences
	string output = ""; //output is empty string
	subsequence(s,output,v);

	sort(v.begin(),v.end(),compare); // sort on the basis of the given parameters

	for(auto s : v){ // print the output
		cout<< s << ",";
	}

	return 0;
}