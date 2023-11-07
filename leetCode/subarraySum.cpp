#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Brute force approach
// int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
//     int num = 0;
//     int left = 0, right = 1;
//     for (left = 0; left < arr.size(); left++)
//     {
//         int sum = 0;
//         for (right = left; right < arr.size(); right++)
//         {
//             sum += arr[right];
//             if (sum == k) {
//                 num++;
//             }
            
//         }
        
//     }
    
    
//     return num;
// }

int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> umpp;
    umpp[0] = 1;
    int preSum = 0, count = 0 ;
    for (int i = 0; i < nums.size(); i++)
    {
        preSum += nums[i];
        int rmv = preSum - k; // {1,2,3,-3,1,1,1,4,2,-3};
        count += umpp[rmv];
        umpp[preSum] += 1;
    }
    return count;
}

int main()
{
    vector<int> v = {1,2,3,-3,1,1,1,4,2,-3};
    int k;
    k = subarraySum(v, 3);
    cout << k << endl;
    return 0;
}