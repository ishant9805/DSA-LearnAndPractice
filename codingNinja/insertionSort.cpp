#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& nums)
{
    int size = nums.size();
    int tmp = 0;
    int r = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (nums[j] < nums[j-1])
            {
                swap(nums[j], nums[j - 1]);
            }
            
        }         
    }
}

int main()
{
    vector<int> v = {14, 9, 15, 12, 6, 8, 13};
    insertionSort(v);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}