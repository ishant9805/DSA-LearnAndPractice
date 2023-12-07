#include<iostream>
#include<vector>

using namespace std;
// Used STL in C++
// pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
// {
//     // Write your code here
//     pair<int, int> ans = {-1, -1};
//     ans.first = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
//     ans.second = upper_bound(arr.begin(), arr.end(), k) - arr.begin() - 1;
//     if(arr[ans.first] != k) {
//         ans.first = -1;
//     }
//     if(arr[ans.second] != k) {
//         ans.second = -1;
//     }
//     return ans;
// }

// Using custom upper & lower bound
vector<int> searchRange(vector<int> &arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1;
    vector<int> ans = {n - 1, n};
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= target)
        {
            high = mid;
            ans[0] = mid;
        } else {
            low = mid + 1;
        }
    }
    low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            ans[1] = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if(ans[1] > 0) ans[1]--;
    if (ans[0] <= n - 1 && ans[1] <= n - 1) {
        if (arr[ans[0]] != target) ans[0] = -1;
        if (arr[ans[1]] != target) ans[1] = -1;
        return ans;
    } else {
        return {-1, -1};
    }
    return ans;
}

int main()
{
    vector<int> v = {3,4,13,13,13,20,40};
    v = searchRange(v, 13);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    v = {0, 0, 1, 1, 2, 2, 2, 2};
    v = searchRange(v, 2);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    v = {1, 1, 1, 1, 2, 3, 3, 3, 3, 4};
    v = searchRange(v, 4);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}