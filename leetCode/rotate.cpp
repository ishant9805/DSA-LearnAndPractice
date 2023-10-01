#include<iostream>
#include<vector>
using namespace std;

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