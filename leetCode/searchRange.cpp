#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            if (res.size() <= 1)
            {
                res.push_back(i);
            }               
            else
            {
                res[1] = i;
            }
        }
        
    }
    if (res.size() == 1)
    {
        res.push_back(res[0]);
    }
    
    if (res.size() == 0)
    {
        return {-1, -1};
    }
    return res;
}

int main()
{
    vector<int> arr = {1};
    arr = searchRange(arr, 1);
    cout << "[";
    for (int i = 0; i < arr.size() - 1; i++)
    {
       cout << arr[i] << ", ";
    }
    cout << arr[arr.size() - 1] << "]" << endl;
    return 0;
}