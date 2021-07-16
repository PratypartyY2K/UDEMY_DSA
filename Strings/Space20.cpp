/*
Given a string, write a funciton to replace all spaces in a string with '%20'.
It is given that the string has sufficient space at the end to hold the additional
characters.
*/

#include <bits/stdc++.h>
using namespace std;

void newString(char *old) {
    int space = 0;
    for(int i=0;i<strlen(old);i++) {
        if(old[i] == ' ') {
            space++;
        }
    }
    cout << strlen(old) << endl;
    int index = strlen(old) + 2*space;
    old[index] = '\0';
    
    for(int i=strlen(old)-1; i>=0; i--) {
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
}

int main() {

    char input[1000]; //"hello world, how are you?";
    cin.getline(input, 1000);
    newString(input);
    cout << input << endl;
    return 0;
}