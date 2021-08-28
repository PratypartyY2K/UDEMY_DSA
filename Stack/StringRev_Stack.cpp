// C++ program for reversing a word using Stack STL (Standard Template Library)

#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

void reverse(char *word) {
    // create an empty string stack
    stack <char> S;
    // loop for push
    for(int i = 0; i < strlen(word); i++) {
        S.push(word[i]);
    }
    //loop for pop
    for(int i = 0; i < strlen(word); i++) {
        word[i] = S.top();
        S.pop();
    }
}

int main() {
    char word[100];
    cout << "Enter a string";
    cin >> word;
    reverse(word);
    cout << "Output = " << word << "\n";
    return 0;
}

/* 
Time Complexity = O(n) -> two for loops in reverse function
Space- Complexity = O(n) -> additional memory is used for Stack
*/