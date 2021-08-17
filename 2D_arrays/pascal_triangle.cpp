//https://en.wikipedia.org/wiki/File:PascalTriangleAnimated2.gif

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printPascal(int n) {
    
    vector<vector<int>> result;
	for(auto i=0;i<n;++i)
	{
   		result.push_back(vector<int>(i+1,1));
 		for(auto j=1; j<i; ++j) 
 		{
 			result[i][j] = result[i-1][j-1] + result[i-1][j];
 		}
  	}
  	return result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> result;
    result = printPascal(n);
    for(int i=0;i<result.size();i++) {
        for(int j=0;j<result[i].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}