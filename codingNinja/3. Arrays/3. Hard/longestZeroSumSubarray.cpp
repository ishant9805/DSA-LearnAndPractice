#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// int getLongestZeroSumSubarrayLength(vector<int> &arr){
// 	// Write your code here.
//     int maxi = 0;
// 	for (int i = 0; i < arr.size(); i++)
//     {
//         for (int j = i; j < arr.size(); j++)
//         {
//             int sum = 0;
//             int cnt = 0;
//             for (int k = i; k <= j; k++)
//             {
//                 sum += arr[k];
//             }
//             if (sum == 0) {
//                 cnt = j - i + 1;
//                 maxi = max(maxi, cnt);
//             }
            
//         }
        
//     }
//     return maxi;
// }

// Kadane's Algo
int getLongestZeroSumSubarrayLength(vector<int> &arr) {
    int sz = arr.size();
    unordered_map<int, int> umpp;
    int sum = 0;
    int maxi = 0;
    for (int i = 0; i < sz; i++)
    {
        sum += arr[i];
        if (sum == 0 ) maxi = i + 1;
        else {
            if (umpp.find(sum)!= umpp.end())
                maxi = max(maxi, i - umpp[sum]);
            else umpp[sum] = i;
        }
    }
    return maxi;
}

int main()
{
    // vector<int> v = {1,-1,0,0,1};
    // vector<int> v = {1,-1,3,2,-2,-8,1,7,10,23};
    vector<int> v = {19, 0, 32, 49, 21, 25, 23, 31, 20, 5, 50, 49, 9, 44, 10, 13, 3, 31, 48, 22, -1};
    int k = getLongestZeroSumSubarrayLength(v);
    cout << k << endl;
    return 0;
}