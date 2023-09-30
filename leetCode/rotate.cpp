#include<iostream>
#include<vector>
using namespace std;

vector<int> rotateArray(vector<int> &nums, int n) {
    int tmp = nums[0];
    for (int i = 0; i < n - 1; i++)
    {
        nums[i] = nums[i + 1];
    }
    nums[n - 1] = tmp;
    return nums;
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    for (int i = 0; i <= k; i++)
    {
        nums = rotateArray(nums, n);
    }
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7};
    rotate(v, 3);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}