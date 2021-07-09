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
    int prefix_product = 1;
    int suffix_product = 1;
    
    for(int x=1;x<n;x++) {
        //calculate suffix
        for(int i=x+1;i<n;i++) {
            suffix_product *= arr[i];
        }
        //calculate prefix
        for(int j=x-1;j>=0;j--) {
            prefix_product *= arr[j];
        }
        output[x] = prefix_product * suffix_product;
    }    
    
    return output;
}

int main() {

    vector<int> arr{1,2,3,4,5};
    auto p = productArray(arr);
    for(int i=0;i<p.size();i++) {
        cout << "{" << p[i] << ",";
    }
    cout << "}";
    return 0;
}