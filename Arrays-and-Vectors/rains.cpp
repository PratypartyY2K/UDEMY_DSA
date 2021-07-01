#include <iostream>
#include <vector>
using namespace std;

int trappedWater(vector<int> heights) {

    int n = heights.size();
    if(n<=2) {
        return 0;
    }

    //left max, right max
    vector<int> left(n,0), right(n,0);
    // for the first and the last element, the lest_max will be the first ele
    // the right_max will be last element
    // and when we encounter any other max, we can update wither left_max or right_max
    left[0] = heights[0];
    right[n-1] = heights[n-1];

    for(int i=1;i<n;i++) {
        // Updating L[i] by choosing the maximum between the current element(h[i]) and whatever we have seen till now(L[i-1])
        left[i] = max(left[i-1],heights[i]);
        // Updating the ith index from right using that index's height and whatever we have seen on the right
        right[n-i-1] = max(right[n-i],heights[n-i-1]);
    }

    //calculate water
    int water=0;
    for(int i=0;i<n;i++) {
        water += min(left[i], right[i]) - heights[i];
    }

    return water;
}

int main () {

    vector<int> water = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trappedWater(water) << endl;

    return 0;
}