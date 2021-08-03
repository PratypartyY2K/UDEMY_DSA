#include<bits/stdc++.h>
using namespace std;
/* O(NlogN)
bool compare(pair<string,int> a, pair<string,int> b) {
    return a.second <=b.second;
}


int badness(vector<pair<string,int> > teams){
    //Complete this function to return the min badness
    sort(teams.begin(), teams.end(),compare); // sorting the teams in NlogN time
    int n = teams.size(); // number of teams
    int badness = 0;
    for(int pos=0;pos<n;pos++){
        int diff = teams[pos].second - (pos+1);
        badness += abs(diff);
    }
    
    return badness;
}
*/
int main() {

    vector<pair<string,int>> teams = { {"noobz", 1}, {"llamas",2}, {"Winn3rz",2}, {"5thwheel",1}, {"NotoricCoders",5}, {"StrangeCase",7}, {"WhoKnows",7} };
    int result = badness(teams);
    cout << result << endl;
    return 0;
}