#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

// vector<int> separateNegativeAndPositive(vector<int> &nums){
//     // Write your code here.
//     vector<int> res;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if(nums[i] < 0) {
//             res.push_back(nums[i]);
//         }
//     }
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if(nums[i] >= 0) {
//             res.push_back(nums[i]);
//         }
//     }
//     return res;
// }

// optimized solution
vector<int> separateNegativeAndPositive(vector<int> &nums){
    int n = nums.size();
    int low = 0, high = n-1;
    while(low <= high) {
        if (nums[low] < 0) {
            low++;
            continue;
        }
        if (nums[high] >= 0) {
            high--;
            continue;
        }
        if (nums[low] >= 0 && nums[high] < 0){
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
    }
    return nums;
}

int main()
{
    vector<int> v = { 1, 2, -3, 4, -4, -5 }; // 1 2 3 4 5 6 10 9 8 7 => m + (n-m) / 2
    v = separateNegativeAndPositive(v);
    cout << "[ ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << "]" << endl;
}