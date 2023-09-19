#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

pair<int,int> findMaxFreq(vector<int>& nums) {
    unordered_map<int, int> umpp;
    pair<int,int> max;
    max.second = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        umpp[nums[i]]++;
    }
    for (auto it : umpp)
    {
        if (it.second >= max.second)
        {
            max.second = it.second;
            max.first = it.first;
        }
    }
    
    return max;
}

int maxFrequency(vector<int>& nums, int k) {
    int max = findMaxFreq(nums).first;
    for (int i = 0; i < nums.size(); i++)
    {
        if (k >= (max - nums[i]) && max - nums[i] >= 0 && k >= 0)
        {
            k = k - (max - nums[i]);
            nums[i] = max;
        }
    }
    max = findMaxFreq(nums).second;
    return max;
}

int main()
{
    int n = 5;
    vector<int> v = {1, 2, 4};
    int m = maxFrequency(v, n);
    cout << m;
    return 0;
}