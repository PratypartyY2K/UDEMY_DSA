#include<bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int> result = {};
    int index; vector<int> res;
    
        index = big.find(small);
        res.push_back(index);
        index++;
    
    return res;

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