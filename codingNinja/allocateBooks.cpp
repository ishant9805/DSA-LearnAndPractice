#include<iostream>
#include<vector>
#include<numeric>
#include<bits/stdc++.h>

using namespace std;

int bookAlloc(vector<int> &arr, int k) {
    int stu = 1; long long pStud = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (pStud + arr[i] <= k)
        {
            pStud += arr[i];
        } else {
            pStud = arr[i];
            stu++;
        }
    }
    return stu;
}
// Brute Force
// int findPages(vector<int>& arr, int n, int m) {
//     if (m > n) return -1;
//     int maxi = *max_element(arr.begin(), arr.end());
//     int sumo = accumulate(arr.begin(), arr.end(), 0);
//     for (int i = maxi; i < sumo; i++)
//     {
//         if (bookAlloc(arr, i) == m) return i;
//     }
//     return sumo;
// }

// Binary Search 
int findPages(vector<int> &arr, int n, int m) {
    if (m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int st = bookAlloc(arr, mid);
        if (st > m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}
int main()
{
    vector<int> v = {12,34,67,90};
    cout << findPages(v, 4, 2) << endl;
    vector<int> v2 = {25,46,28,49,24};
    cout << findPages(v2, 5, 4) << endl;
    return 0;
}