#include<iostream>
#include<vector>
using namespace std;

// vector<int> rotate(vector<int>& nums, int n)
// {
//     vector<int> rot(n);
//     for (int i = 0; i < n; i++)
//     {
//         int k = i + 1;
//         if (k < n)
//         {
//             rot[i] = nums[k];
//         }
//         else{
//             k = k - n;
//             rot[i] = nums[k];
//         }
        
//     }
//     return rot;
// }
// Optimal Solution
vector<int> rotateArray(vector<int> &nums, int n) {
    int tmp = nums[0];
    for (int i = 0; i < n - 1; i++)
    {
        nums[i] = nums[i + 1];
    }
    nums[n - 1] = tmp;
    return nums;
}

int main()
{
    vector<int> v = {3,4,1,5,2};
    v = rotateArray(v, v.size());
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}