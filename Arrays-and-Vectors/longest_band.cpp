#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


int longestBand(vector<int> arr) {
    int n = arr.size();
    unordered_set<int> s;

    //Data inside a set
    for(int x: arr) {
        s.insert(x);
    }

    //Iterate ove the arr

    int largestLen = 1; // there always be one element in a band

    for(auto element : s) {
        int parent = element-1;

        if(s.find(parent) == s.end()) { //parent does not exist
            //find entire band (or) chain starting from element

            int next_no = element + 1;
            int cnt=1; //element also belongs to the band

            while(s.find(next_no) != s.end()) {
                next_no++;
                cnt++;
            }

            if(cnt>largestLen) {
                largestLen = cnt;
            }
        }
    }
    return largestLen;

}

int main() {
    
    vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout << longestBand(arr) << endl;

    return 0;
}