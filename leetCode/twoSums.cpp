#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int a = 0;
    int b = 0;
    for (int i = 0; i < nums.size()-1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                a = i;
                b = j;
            }
        }
    }
    return {a, b};
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