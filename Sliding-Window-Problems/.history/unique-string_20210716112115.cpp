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

//Brute Force
#include<bits/stdc++.h>
using namespace std;

int compare(int head,int tail,string input)
{
     int i,j;
     for(i = head;i <= tail;i++)
         for(j = i + 1;j <= tail;j++)
             if(input[i] == input[j])
                 return 0;
     return 1;
}


int main() {
    string input;
    cin >> input;

    int length = input.length();//string length
    int i,j,head,tail;
    for(i = length-1;i >= 0;i--){
        head = 0;
        tail = i;
        while(tail <= length-1){
            if(compare(head,tail,input)) {//If there is no repeated string, the length will be counted and exited
                printf("%d",i+1);
                return 0;
            }
            head++;
            tail++;
        }
    }
    return 0;
}
