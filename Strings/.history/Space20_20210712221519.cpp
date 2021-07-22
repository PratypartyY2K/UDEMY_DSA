/*
Given a string, write a funciton to replace all spaces in a string with '%20'.
It is given that the string has sufficient space at the end to hold the additional
characters.
*/

#include <bits/stdc++.h>
using namespace std;

string newString(string old) {
    int space = 0; string modString;
    for(int i=0;i<old.size();i++) {
        if(old[i] == ' ') {
            space++;
        }
    }
    cout << old.size() << endl;
    int additional = 2*space;
    
    for(int i=old.size()-1; i>=0; i--) {
        if(old[i] != ' ')
            modString[i+additional] = old[i];
        
        if(old[i] == ' ') {
            modString[i+additional] = '0';
            modString[i+additional-1] = '2';
            modString[i+additional-2] = '%';
        }
        
    }
    return modString;
}

int main() {

    string input = "hello world, how are you?";
    string result = newString(input);
    cout << result;
    return 0;
}