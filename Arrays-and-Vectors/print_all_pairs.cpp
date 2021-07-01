#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//vector<int> pairsum(vector<int> arr, int sum)
void pairSum(vector<int> arr, int sum)
{
    vector<int> result;
    sort(arr.begin(), arr.end());

    for(auto v: arr)
    {
        cout<<v<<",";
    }
    cout<<endl;


    int s=0;   // first index
    int e=arr.size()-1;    // last index
    while(s<e)    //  when first index remains smaller than the last index.
    {
            // storing current sum
         if(arr[s]+arr[e]==sum)
         {
            /*result.push_back(arr[s]);
            result.push_back(arr[e]);	*/
			cout << "[" << arr[s] << "," << arr[e] << "]" << "\n";
			s++; e--;
			
         }
         else if(arr[s]+arr[e]>sum)
         {
             e--;
         }
         else
         {
              s++;
         }
    }

    //return result;


}


int main()
{
    vector<int> arr={3,4,2,1,7,5,9,8,6};   // this is the array, from where we have to extract the pair whose sum is equal to the s;
    int sums=7;   // given sum
    /*vector<int> output= pairsum(arr,sums);  // storing all those pairs in output array.
     for(auto v: output)
     {
         cout<<v<<",";
     }*/
	 pairSum(arr,sums);
    return 0;
}