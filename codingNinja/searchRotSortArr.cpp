#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& arr, int n, int k)
{
    int res = -1;
    int iRot;
    bool toBreak = false;
    for (iRot = 1; iRot <= n;iRot++)
    {
        if (arr[0] > arr[1])
        {
            toBreak = true;
        }
        arr.push_back(arr[0]);
        arr.erase(arr.begin());
        if (toBreak) {
            break;
        }
    }
    cout << "[";
    for (int i = 0; i < arr.size() - 1; i++)
    {
       cout << arr[i] << ", ";
    }
    cout << arr[arr.size() - 1] << "]" << endl;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == k)
        {
            res = mid;
            break;
        } else if (arr[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        
    }

    if (res < n - iRot)
    {
        res += iRot;
    } else {
        res -= (n - iRot);
    }
    
        
    return res;
}


int main()
{
    vector<int> v = {12,15,18,2,4};
    cout << search(v, v.size(), 2) << endl;
    v = {2,3,5,8};
    cout << search(v, v.size(), 3) << endl;
    return 0;
}