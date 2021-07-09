#include <iostream>
#include <vector>
using namespace std;

//Expected Complexity O(N)

//O(N^2) time complexity
/*
vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    
    //update the output array and return
    //complete the code
    
    
    for(int x=1;x<n;x++) {
        int prefix_product = 1;
        int suffix_product = 1;
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
*/

//O(n) time complexity, O(n) space complexity
/*
vector<int> productArray(vector<int> arr) {
    int n = arr.size();
    vector<int> output(n,1);
    
    vector<int> prefix_product(n);
    vector<int> suffix_product(n);

    prefix_product[0] = 1;
    suffix_product[n-1] = 1;

    for(int i=1;i<n;i++) {
        prefix_product[i] = prefix_product[i-1] * arr[i-1];
    }

    for(int i=n-2;i>=0;i--) {
        suffix_product[i] = suffix_product[i+1] * arr[i+1];
    }

    for(int i=0;i<n;i++) {
        output[i] = prefix_product[i] * suffix_product[i];
    }

    return output;
}
*/

//O(n) time and O(1) space

vector<int> productArray(vector<int> arr) {
    int n = arr.size();
    vector<int> output(n);
    
    output[0] = 1;
    
    for(int i=1;i<n;i++) {
        output[i] = output[i-1] * arr[i-1];
    }

    int R = 1;
    for(int i=n-1;i>=0;i--) {
        output[i] = output[i+1] * R;
        R = R*arr[i];
    }

    return output;
}
int main() {

    vector<int> arr{1,2,3,4,5};
    auto p = productArray(arr);
    for(int i=0;i<p.size();i++) {
        cout << p[i] << "\n";
    }
    return 0;
}