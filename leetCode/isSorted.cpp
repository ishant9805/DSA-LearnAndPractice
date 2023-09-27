#include<iostream>
#include<vector>
using namespace std;

vector<int> rotate(vector<int>& nums, int rotNum)
{
    vector<int> rot(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        int k = i + rotNum;
        if (k < nums.size())
        {
            rot[i] = nums[k];
        }
        else{
            k = k - nums.size();
            rot[i] = nums[k];
        }
        
    }
    return rot;
}

bool isSorted(vector<int> a) {
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (!(a[i] <= a[i + 1]))
        {
            return false;
        }
        
    }
    return true;
}

bool check(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> temp;
        temp = rotate(nums, i);
        if (isSorted(temp))
        {
            return true;
        }
        
    }
    return false;
}

int main()
{
    vector<int> v = {4,3,5,1,2};
    bool k = check(v);
    cout << k << endl;
    return 0;
}