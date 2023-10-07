#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// int missingNumber(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] != i)
//         {
//             return i;
//         }
//     }
//     return nums.size();
// }

// Had an out of the box thought
int missingNumber(vector<int> v) {
    int vS = v.size();
    int expectedSum = vS * (vS + 1) / 2;
    int actualSum = accumulate(v.begin(), v.end(), 0);
    return expectedSum - actualSum;
}

int main()
{
    vector<int> nums = {0,1};
    int n = missingNumber(nums);
    cout << n << endl;
    return 0;
}