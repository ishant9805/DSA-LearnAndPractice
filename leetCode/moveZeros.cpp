#include<iostream>
#include<vector>
using namespace std;

// Problem Link: https://leetcode.com/problems/move-zeroes/description/

// My Own Solution
// void moveZeroes(vector<int>& nums) {
//     int n = nums.size();
//     int k = 0;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (nums[i] == 0)
//         {
//             nums.erase(nums.begin() + i);
//             k++;
//         }
//     }
//     for (int i = 0; i < k; i++)
//     {
//         nums.push_back(0);
//     }
// }

// Found Optimal solution Thanks to https://leetcode.com/freshfreshman/
void moveZeroes(vector<int>& nums) {
    int i=0,j=0;
    while(j<nums.size()){
        if(nums[j]!=0){
            swap(nums[i],nums[j]);
            i++;
        }
        j++;
    }
}

int main()
{
    vector<int> v = {0,1,0,3,12};
    moveZeroes(v);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}