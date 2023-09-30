#include<iostream>
#include<vector>
using namespace std;

// vector<int> rotateArray(vector<int> &nums, int n) {
//     int tmp = nums[0];
//     for (int i = 0; i < n - 1; i++)
//     {
//         nums[i] = nums[i + 1];
//     }
//     nums[n - 1] = tmp;
//     return nums;
// }

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 1)
        return;
    vector<int> tmp;
    int l = n - k;
    for (int i = l; i < n; i++)
    {
        tmp.push_back(nums[i]);
    }
    
    for (int i = 0; i < l; i++)
    {
        tmp.push_back(nums[i]);
    }
    for (int i = 0; i < n; i++)
    {
        nums[i] = tmp[i];
    }
}

int main()
{
    vector<int> v = {-1}; // {}
    rotate(v, 2);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}