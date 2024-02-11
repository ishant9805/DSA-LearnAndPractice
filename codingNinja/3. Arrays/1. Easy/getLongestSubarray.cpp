#include<iostream>
#include<vector>
#include<map>
using namespace std;

int getLongestSubarray(vector<int>& nums, int k){
    // Dictionary method
    map<long long, int> preSumMap;
    long long sum = 0; int maxLen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum +=nums[i];
        if (sum == k) maxLen = max(maxLen, i + 1);
        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end()) maxLen = max(maxLen, i - preSumMap[rem]);
        if (preSumMap.find(sum) == preSumMap.end()) preSumMap[sum] = i;
    }
    
    return maxLen;
}

int main()
{
    vector<int> v = {-1, 0, 1, 1, -1, -1, 0};
    int x = getLongestSubarray(v, 0);
    cout << "Number of elements in longest subarray: " << x << endl;
    return 0;
}