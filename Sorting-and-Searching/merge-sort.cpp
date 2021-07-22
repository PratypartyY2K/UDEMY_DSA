#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &array, int s, int e) {

}
void mergesort(vector<int> &array, int s, int e) {

}

int main() {
    vector<int> arr{10,5,2,0,7,6,4};

    int s = 0;
    int e = arr.size()-1;
    mergesort(arr,s,e);
    for(int x: arr) {
        cout << x << ",";
    }
    cout << endl;
    return 0;
}