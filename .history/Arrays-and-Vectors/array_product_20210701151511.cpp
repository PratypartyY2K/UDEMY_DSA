#include <iostream>
#include <vector>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    
    //update the output array and return
    //complete the code
    
    
    
    return output;
}

int main() {

    vector<int> arr{1,2,3,4,5};
    auto p = productArray(arr);
    for(int i=0;i<p.size();i++) {
        cout << "{" << p[i] << "," 
    }
    cout << "}";
    return 0;
}