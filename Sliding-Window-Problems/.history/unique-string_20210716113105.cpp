// Unique Substring

/*
Given a string, write a function to find the largest substring with unique characters (no duplicates)

Sample Input
------------
prateekbhaiya
aabcb

Sample Output
-------------
ekbhaiya
abc
*/

// brute-force method, where we find each string and then compare.

#include <bits/stdc++.h>
using namespace std;

void lengthOfLongestSubstring(string s)
{
    //Get the length of string
    int n = s.length();
     
    int i = 0, j = 0;
    int maxLen = 0;
     
    // Set all characters as not-existing
    bool exist[256] = { false };
     
    while (j < n)
    {
        // Check if the character exists
        if (exist[s[j]])
        {
            maxLen = max(maxLen, j-i);
            while (s[i] != s[j])
            {
                exist[s[i]] = false;
                i++;
            }
             
            i++;
            j++;
        }
        else
        {
            exist[s[j]] = true;
            j++;
        }
    }

    for(int k=i;i<=j;k++) {
        cout << s[i] << " ";
    }
     
    /* maxLen = max(maxLen, n-i);
    return maxLen; */
}

int main() {
    string input;
    cin >> input;
    lengthOfLongestSubstring(input);
    cout << "\n";
    return 0;
}