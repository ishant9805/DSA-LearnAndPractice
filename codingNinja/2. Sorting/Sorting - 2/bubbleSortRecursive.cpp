#include<iostream>
#include<vector>
using namespace std;

void bubbleSortRec(vector<int>& nums, int n) {
    if (n == 0)
    {
        return;
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            swap(nums[i], nums[i + 1]);
        }
    }
    bubbleSortRec(nums, n - 1);
}

int main()
{
    vector<int> v = {9, 3, 6, 2, 0};
    bubbleSortRec(v, v.size());
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}