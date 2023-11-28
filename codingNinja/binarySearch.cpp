#include<iostream>
#include<vector>

using namespace std;

int bSearch(vector<int> &nums, int low, int high, int target) {
    int mid = (high + low) / 2;
    if (high == low && nums[mid] != target)
    {
        return -1;
    }
    
    if (nums[mid] == target) return mid;
    else if (nums[mid] > target) return bSearch(nums, low, mid, target);
    else return bSearch(nums, mid + 1, high, target);
}

int search(vector<int> &nums, int target) {
    return bSearch(nums, 0, nums.size() - 1, target);
}

int main()
{
    // vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    vector<int> v = {1, 3, 7, 9, 11, 12, 45};
    int k = search(v, 3);
    cout << k << endl;
    return 0;
}