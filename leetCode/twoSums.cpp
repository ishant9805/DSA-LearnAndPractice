#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    // Double loop method
    // int a = 0;
    // int b = 0;
    // for (int i = 0; i < nums.size()-1; i++)
    // {
    //     for (int j = i + 1; j < nums.size(); j++)
    //     {
    //         if (nums[i] + nums[j] == target)
    //         {
    //             a = i;
    //             b = j;
    //         }
    //     }
    // }
    // return {a, b};
    // Hashmap method
    // map<int, int> mp; int diff = 0; int n = nums.size();
    // for (int i = 0; i < n; i++)
    // {
    //     diff = target - nums[i];
    //     if (mp.find(diff) != mp.end())
    //     {
    //         return {mp[diff], i};
    //     }
    //     mp.insert({nums[i], i});        
    // }
    // return {-1,-1};
    //
    // Two -pointer method 🙂
    int n = nums.size();
    sort(nums.begin(), nums.begin() + n);
    int left = 0; int right = n - 1; int sum = 0;
    while (left < right)
    {
        sum = nums[left] + nums[right];
        if (sum == target) return {left, right};
        if (sum > target) right--;
        if (sum < target) left++;
    }
    return {-1, -1};
}

int main()
{
    int n;
    cin >> n;
    int k;
    int trget;
    cout << "Target: ";
    cin >> trget;
    vector<int> v;
    while (n > 0)
    {
        cin >> k;
        v.push_back(k);
        n--;
        k = 0;
    }
    vector<int> tSum;
    tSum = twoSum(v, trget);
    cout << "[";
    for (int i = 0; i < tSum.size(); i++)
    {
        cout << tSum[i]<<",";
    }
    cout << "]";
    return 0;
}