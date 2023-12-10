#include<iostream>
#include<vector>

using namespace std;

bool search(vector<int>&A, int key) {
    // Write your code here.
    int low = 0, n = A.size(), high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // if found
        if (A[mid] == key)
        {
            return true;
        }
        if (A[low] == A[mid] && A[mid] == A[high]) {
            low++;
            high--;
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
    vector<int> v = {1,0,1,1,1};
    string res = search(v, 0) ? "True" : "False";
    cout << res << endl;
    v = {8,2,3,3,3};
    res = search(v, 2) ? "True" : "False";
    cout << res << endl;
    return 0;
}