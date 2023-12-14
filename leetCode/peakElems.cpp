#include<iostream>
#include<vector>

using namespace std;

// Brute Force
int findPeakElement(vector<int> &arr) {
    int n = arr.size();
    if (n == 1 || arr[0] > arr[1]) return 0;
    if (arr[n-1] > arr[n-2]) return n-1;
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
        {
            return i;
        }
        
    }
    return -1;
}

// Binary Search
int findPeakElement(vector<int> &arr) {
    int n = arr.size();
    if (n == 1 || arr[0] > arr[1]) return 0;
    if (arr[n-1] > arr[n-2]) return n-1;
    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        // if mid is peak and mid == 0 or mid == n - 1
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]){
            return mid;
        } // if peak is in right of mid
        else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        } // if peak is in left of mid
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    // vector<int> v = {1,8,1,5,3};
    // cout << findPeakElement(v) << endl;
    vector<int> v = {1,2,3,1};
    cout << findPeakElement(v) << endl;
    return 0;
}