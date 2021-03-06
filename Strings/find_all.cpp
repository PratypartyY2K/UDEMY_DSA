/*
Implement a function that returns a list of all occurences of a given
substring inside a big string.
Return empty vector if smaller string is not present inside bigger string.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int> result = {};
    int index = big.find(small, 0); // first occurrence
    result.push_back(index);
    while(index!=-1) {
        index = big.find(small,index+1);
        if(index!=-1)
            result.push_back(index);
    }
    return result;

}

int main() {
    
    string bigString = "I liked the movie, acting in movie was great!";
    string smallString = "movie";
    auto result = stringSearch(bigString, smallString);
    for(int num : result) {
        cout << num << ",";
    }
    cout << "\n";
    return 0;
}