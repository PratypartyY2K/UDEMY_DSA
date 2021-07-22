#include<bits/stdc++.h>
using namespace std;

string normalize(const string &sentence) {
    string copy = sentence;
    //Make the changes in copy, and return it
    int check=0;                // ststus of space
    int i=0;                    // for loop
    while(sentence[i]){                      
        if(check==0){
            copy[i]=toupper(sentence[i]);     //conversion of string takes place here
            check=1;
        }else if(isspace(sentence[i]))       // change status of check if move to another word
            check=0;
        else if(check==0) {
            copy[i] = tolower(sentence[i]);
        }
        i++;
    }
    
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