/*
You are given a running stream of characters, output the first non repeating character in the string formed so far after every new character you get in input. Output -1 if such a character doesn't exist

Input
-----
a a b c c b c d

Output
------
a -1 b b b -1 -1 d
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

vector<char> FindFirstNonRepeatingCharacter(string S){
    
    vector<char> result;
    
    queue<char> q;
    int charCount[MAX_CHAR] = {0};
 
    // traverse whole stream
    for (int i = 0; S[i]; i++) {
 
        // push each character in queue
        q.push(S[i]);
 
        // increment the frequency count
        charCount[S[i] - 'a']++;
 
        // check for the non pepeating character
        while (!q.empty()) {
            if (charCount[q.front() - 'a'] > 1) {
                q.pop();
            }
            else {
                result.push_back(q.front());
                break;
            }
        }
 
        if (q.empty())
            result.push_back('-1');
    }
    return result;
}

int main() {
    string input = "aabcbcd";
    vector<char> res = FindFirstNonRepeatingCharacter(input);
    for(char x:res) {
        cout << x << " ";
    }
    return 0;
}