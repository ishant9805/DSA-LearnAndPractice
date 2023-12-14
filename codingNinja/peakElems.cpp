#include<iostream>
#include<vector>

using namespace std;

// Brute Force
int findPeakElement(vector<int> &arr) {
    int n = arr.size();
    if (arr[0] > arr[1]) return 0;
    if (arr[n-1] > arr[n-2]) return n-1;
    for (int i = 1; i < n - 2; i++)
    {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
        {
            return i;
        }
        
    }
    return -1;
}

// Binary Search

int main()
{
    vector<int> v = {1,8,1,5,3};
    cout << findPeakElement(v) << endl;
    return 0;
}