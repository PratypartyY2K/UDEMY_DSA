#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


pair<int,int> minDifference(vector<int> a,vector<int> b){
    //Complete this method
    int n = a.size(); //length of first array
    int m = b.size(); //length of second array
    
    pair<int,int> res;
    int min_diff = INT_MAX; // minimum difference
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(abs(a[i]-b[j])<min_diff) {
                min_diff = abs(a[i]-b[j]);
                res.first = a[i];
                res.second = b[j];
            }
        }
    }
    return res;
}

int main() {
    
    vector<int> a{23,5,10,17,30};
    vector<int> b{26,134,135,14,19};
    auto result = minDifference(a,b);
    cout << result.first << "," << result.second << endl;
    
    return 0;
}