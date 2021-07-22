/*
Given a string, write a funciton to replace all spaces in a string with '%20'.
It is given that the string has sufficient space at the end to hold the additional
characters.
*/

#include <bits/stdc++.h>
using namespace std;

string newString(string old) {
    int space = 0;
    for(int i=0;i<old.size();i++) {
        if(old[i] == ' ') {
            space++;
        }
    }
    cout << old.size() << endl;
    int index = old.size() + 2*space;
    old[index] = '\0';

    int additional = 2*space;
    old.resize(old.size() + additional);
    for(int i=old.size()-1; i>=0; i--) {
        if(old[i] != ' ') {
            old[index-1] = old[i];
            index--;
        }
        if(old[i] == ' ') {
            old[index-1] = '0';
            old[index-2] = '2';
            old[index-3] = '%';
            index -= 3;
        }
        
    }
    return old;
}

int main() {

    string input = "hello world, how are you?";
    string result = newString(input);
    cout << result;
    return 0;
}