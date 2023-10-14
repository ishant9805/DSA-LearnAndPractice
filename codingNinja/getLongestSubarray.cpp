#include<iostream>
#include<vector>
using namespace std;

int getLongestSubarray(vector<int>& nums, int k){
    // Two pointer solution
    int left = 0; int right = 0; int n = nums.size();
    long long sum0 = nums[0]; int maxLen = 0;
    while (left < n && right < n)
    {
        if (sum0 > k && left < right)
        {
            sum0 -= nums[left];
            left++;
        }
        if (sum0 == k) maxLen = max(maxLen, right - left + 1);
        right++;
        if (right < n) sum0 += nums[right];
    }
    return maxLen;
}

int main()
{
    vector<int> v = {2,3,5};
    int x = getLongestSubarray(v, 5);
    cout << "Number of elements in longest subarray: " << x << endl;
    return 0;
}