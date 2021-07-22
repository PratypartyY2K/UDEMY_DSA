#include<bits/stdc++.h>
using namespace std;

string normalize(const string &sentence) {
    string copy = sentence;
    //Make the changes in copy, and return it
    for(int i=1;i<copy.size();i++) {
        if(copy[i] and isspace(copy[i-1])) {
            copy[i] = toupper(copy[i]);
        } else 
            copy[i] = tolower(copy[i]);
    }
    copy[0] = sentence[0];
    
    return copy;
}

int main() {

    string input;
    getline(cin,input);
    string result;
    result = normalize(input);
    for(int i=0;i<result.size();i++) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}