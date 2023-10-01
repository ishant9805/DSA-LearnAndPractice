#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.com/problems/rotate-array/description/
// E.g. array = {1,2,3,4,5,6,7} and k = 3
// Reverse the array till kth part => array = {4,3,2,1,5,6,7}
// Reverse the array after kth part => array = {4,3,2,1,7,6,5}
// Reverse the whole array => array = {5,6,7,1,2,3,4}
// It's not my solution, I couldn't solve it 😥

void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.begin() + (nums.size() - k));
    reverse(nums.begin() + (nums.size() - k), nums.begin() + nums.size());
    reverse(nums.begin(), (nums.begin() + nums.size()));
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7}; // {}
    rotate(v, 3);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}