/*
Given a list of 'n' strings S0,S1,S2,......,Sn-1, each consisting of digits and spaces, the number of spaces is the same for each entyry, the goal is to implement a variation of a sort command.

None of the string contains consecutive spaces.

Also, no string starts with a spaces nor ends with it.

Spaces are used to divide string into columns, which can be used as keys in comparisons.

The program has to support the required parameters:

key: integer denoting the column used as akey in comparisions. The left-most column denoted by 1.

reversed: boolean variable indicating whether to reverse the result of comparisions.

comparision-type: either lexicographic or numeric.
                  
                Lexicographic means that we use lexicographical order where for example (122<13).

                Numeric means that we compaer the strings by their numeric values, so (13<122). 
                
                If the comparision type is 'numeric' ad numeric values of keys of Si and Sj are equal for i<j, then Si is considered strictly smaller than Sj because it comes first.
*/

/*
Sample Input
------------
3
92 022
82 12
77 13
2 false numeric

Sample Output
-------------
82 12
77 13
92 022

*/
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

string extractStringAtKey(string str,int key){

	//string tokeniser 
	// hello how are you

	char *s = strtok( (char *)str.c_str(), " ");
	while(key>1){
		s = strtok(NULL," ");
		key--;
	}
	return (string)s;
}

int convertToInt(string s){

	int ans = 0;
	int p = 1;

	for(int i=s.length()-1; i>=0;i--){
		ans += ((s[i]-'0')*p);
		p = p*10;
	}
	return ans;
}
/*
"123"
Extract "3" => '3' - '0' = 3 -> ans = 0 + 3*1 = 3
Extract "2" => '2' - '0' = 2 -> ans = 3 + 2*10 = 23
Extract "1" => '1' - '0' = 1 -> ans = 23 + 1*100 = 123
*/


//                         <S1, K1>              <S2, K2>
bool lexicoCompare(pair<string,string> s1, pair<string,string> s2){
	
    string key1, key2;
	key1 = s1.second;
	key2 = s2.second;
	return key1 < key2;
}

bool numericCompare(pair<string,string> s1, pair<string,string> s2){
	
    string key1, key2;
	key1 = s1.second;
	key2 = s2.second;

	return convertToInt(key1) < convertToInt(key2);
}



int main(){
	
    string s ="20 30 40 50";
	
	int n;
	cin>>n;

	cin.get(); //consume the extra \n

	string temp;
	vector<string> v;
	for(int i=0;i<n;i++){
		getline(cin,temp); //includes white spaces 
		v.push_back(temp);
	}

	int key;
	string reversal,ordering;
	cin >>key >> reversal >> ordering; 


	//1. To extract keys for comparison & store them
	vector<pair<string,string> > vp;  

	for(int i=0;i<n;i++){
		vp.push_back({v[i], extractStringAtKey(v[i],key)});
	}

	//2. Sorting 
	if(ordering=="numeric"){
		sort(vp.begin(),vp.end(),numericCompare);
	}
	else{
		sort(vp.begin(),vp.end(),lexicoCompare);
	}


	//3. reversal
	if(reversal=="true"){
		reverse(vp.begin(),vp.end());
	}

	//4. output
	for(int i=0;i<n;i++){
		cout<< vp[i].first << endl;
	}

	return 0;
}