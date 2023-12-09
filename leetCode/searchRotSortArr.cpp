#include<iostream>
#include<vector>

using namespace std;

// Used BS
int search(vector<int> &arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1, res = -1;
    // Starting BS
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // If found
        if (arr[mid] == target)
        {
            return mid;
        } // if left half is sorted 
        else if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && arr[mid] > target)
            {
                high = mid - 1;
            } else {
                low = mid + 1;
            }            
        } // if right half is sorted 
        else {
            if (arr[mid] < target && target <= arr[high]) {
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
    cout << search(v, 2) << endl;
    v = {2,3,5,8};
    cout << search(v, 3) << endl;
    v = {8, 9, 4, 5};
    cout << search(v, 3) << endl;
    v = {3,1};
    cout << search(v, 1) << endl;
    return 0;
}