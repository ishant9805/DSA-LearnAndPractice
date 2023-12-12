#include<iostream>
#include<vector>

using namespace std;

int findKRotation(vector<int> &arr){
    pair<int,int> ans;
    ans.first = 1e9;
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // if left part is sorted
        if (arr[low] <= arr[mid]) {
            // then first element of that would be lowest thus compare and assign.
            if (arr[low] < ans.first) {
                ans.first = arr[low];
                ans.second = low;
            }
            // leave the left part
            low = mid + 1;
        } // if right part is sorted
        else {
            // assign the first element to ans.first as it would be lowest after comparing
            if (arr[mid] < ans.first) {
                ans.first = arr[mid];
                ans.second = mid;
            }
            // leave the sorted part i.e. is right part
            high = mid - 1;
        }
    }
    return ans.second;
}

int main()
{
    // vector<int> v = {3,4,5,1,2};
    // cout << findKRotation(v) << endl;
    vector<int> v = {2,3,4,1};
    cout << findKRotation(v) << endl;
    return 0;
}