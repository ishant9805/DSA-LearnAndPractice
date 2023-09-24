#include<iostream>
#include<vector>
using namespace std;

void insertionSortRec(vector<int>& nums, int n, int index) {
    if (index <= 0)
    {
        return;
    }
    if (nums[index] < nums[index - 1])
    {
        swap(nums[index], nums[index - 1]);
    }
    insertionSortRec(nums, n, index - 1);
}

void insertionSort(vector<int>& nums, int n) {
    for (int ii = 0; ii < n; ii++)
    {
        insertionSortRec(nums, n, ii);
    }
    
}

int main()
{
    vector<int> v = {9, 3, 6, 2, 0};
    insertionSort(v, v.size());
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}