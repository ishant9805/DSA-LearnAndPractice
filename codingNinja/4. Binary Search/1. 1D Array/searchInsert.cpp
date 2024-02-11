#include<iostream>
#include<vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int ans = n;
    int low = 0, high = n -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {1,3,5,6};
    int k = searchInsert(v, 5);
    cout << k << endl;
    k = searchInsert(v, 2);
    cout << k << endl;
    k = searchInsert(v, 7);
    cout << k << endl;
    return 0;
}