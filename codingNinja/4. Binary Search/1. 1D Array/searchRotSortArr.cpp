#include<iostream>
#include<vector>

using namespace std;

// int search(vector<int>& arr, int n, int k)
// {
//     int res = -1;
//     int iRot;
//     bool toBreak = false;
//     for (iRot = 1; iRot <= n;iRot++)
//     {
//         if (arr[0] > arr[1])
//         {
//             toBreak = true;
//         }
//         arr.push_back(arr[0]);
//         arr.erase(arr.begin());
//         if (toBreak) {
//             break;
//         }
//     }
//     cout << "[";
//     for (int i = 0; i < arr.size() - 1; i++)
//     {
//        cout << arr[i] << ", ";
//     }
//     cout << arr[arr.size() - 1] << "]" << endl;
//     int low = 0, high = n - 1;
//     while (low <= high)
//     {
//         int mid = (low + high) / 2;
//         if (arr[mid] == k)
//         {
//             res = mid;
//             break;
//         } else if (arr[mid] < k) {
//             low = mid + 1;
//         } else {
//             high = mid - 1;
//         }
        
//     }

//     if (res < n - iRot)
//     {
//         res += iRot;
//     } else {
//         res -= (n - iRot);
//     }
    
        
//     return res;
// }

// Used BS
int search(vector<int> &arr, int n, int target) {
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return mid;
        } else if (arr[low] < arr[mid]) {
            if (arr[mid] >= target && arr[low] <= target)
            {
                high = mid - 1;
            } else {
                low = mid + 1;
            }            
        } else {
            if (arr[mid] <= target && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}


int main()
{
    vector<int> v = {12,15,18,2,4};
    cout << search(v, v.size(), 2) << endl;
    v = {2,3,5,8};
    cout << search(v, v.size(), 3) << endl;
    v = {8, 9, 4, 5};
    cout << search(v, v.size(), 3) << endl;
    return 0;
}