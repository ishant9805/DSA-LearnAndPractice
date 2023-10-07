#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i)
        {
            return i;
        }
    }
    return nums.size();
}

int main()
{
    vector<int> nums = {0,1};
    int n = missingNumber(nums);
    cout << n << endl;
    return 0;
}