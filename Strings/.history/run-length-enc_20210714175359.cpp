// Run Length Encoding

/*
Sample Input
------------
bbbaaaadexxxxxx
abc

Sample Output
-------------
b3a4d1e1x6
abc
*/

#include<bits/stdc++.h>
using namespace std;

//str is the input the string
string compressString(const string &str){   
    //complete the function to return output string
    int n = str.length(); string res;
    for(int i=0;i<n;i++) {
        int count=1;
        while(i<n-1 and str[i] == str[i+1]) {
            i++;
            count++;
        }
        cout << count << endl;
        res.push_back(to_string(str[i])); 
        res.push_back(to_string(count));
    }
    if(res.size()>n) {
        return str;
    }
    return res;
}

int main() {
    
    string input;
    cin >> input;
    string result;
    result = compressString(input);
    cout << result << endl;

    return 0;
}