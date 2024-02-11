#include<iostream>
#include<vector>

using namespace std;

bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
    // Write your code here.
    int low = 0, n = A.size(), high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // if found
        if (A[mid] == key)
        {
            return true;
        } // if left part is sorted
        else if (A[low] <= A[mid]) {
            if (A[low] <= key && key < A[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } // if right part is sorted
        else {
            if (A[mid] < key && key <= A[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> v = {3,4,5,0,0,1,2};
    // string res = searchInARotatedSortedArrayII(v, 4) ? "True" : "False";
    // cout << res << endl;
    v = {8,2,3,3,3};
    string res = searchInARotatedSortedArrayII(v, 2) ? "True" : "False";
    cout << res << endl;
    return 0;
}