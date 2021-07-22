#include<bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int> result = {};
    size_t index = big.find(small, 0); // first occurrence

    while(index!=-1) {
        index = big.find(small,index);
        result.push_back(index);
        index++;
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