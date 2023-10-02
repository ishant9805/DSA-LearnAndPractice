#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            nums.erase(nums.begin() + i);
            i--;
            k++;
            n--;
        }
    }
    for (int i = 0; i < k; i++)
    {
        nums.push_back(0);
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