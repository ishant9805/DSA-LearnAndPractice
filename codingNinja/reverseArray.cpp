#include<iostream>
#include<vector>
using namespace std;

vector<int> reverseArrayLoop(int n, vector<int> &nums)
{
    int tmp = 0;
    // [0, 1, 2, 3, 4, 5] n = 6
    for (int i = 0; i < n / 2; i++)
    {
        swap(nums[i], nums[n - i - 1]);
    }
    return nums;
}

void reverseArrRec(int start, int end, vector<int> &nums)
{
    if (start > end)
        return;
    swap(nums[start], nums[end]);
    return reverseArrRec(start + 1, end - 1, nums);
}

vector<int> reverseArray(int n, vector<int> &nums)
{
    reverseArrRec(0, n - 1, nums);
    return nums;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v = {7, 4, 6, 1, 8, 2};
    v = reverseArray(v.size(), v);
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ",";
    }
    
    cout << "]";
    return 0;
}