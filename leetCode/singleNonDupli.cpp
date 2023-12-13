#include<iostream>
#include<vector>

using namespace std;

// Brute Force
int singleNonDuplicate(vector<int>& arr) {
    // when size > 1 and the first element is single
    if (arr.size() > 1 && arr[0] != arr[1]) {
        return arr[0];
    }
    // when any element is single till size - 2
    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (arr[i - 1] == arr[i] || arr[i] == arr[i + 1]) continue;
        else return arr[i];
    }
    // if none of elements are single till size - 2 then arr[size - 1] is single
    return arr[arr.size() - 1];   
}

int singleNonDuplicate(vector<int>& arr) {
	int sz = arr.size();
    // If arr contains only one element, obviously it would be the single one
    if (sz == 1) return arr[0];
    // if 0th != 1st element of arr, then 0th will be single as arr is sorted
    if (arr[0] != arr[1]) return arr[0];
    // same will happen to last element
    if (arr[sz - 2] != arr[sz - 1]) return arr[sz - 1];
    // eliminate the first and last for safety
    int low = 1, high = sz - 2;
    // Applying BS
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // If found
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) return arr[mid];
        // Either if we are at odd and left is equal or we are at even and right is equal
        // then it means element is in right of mid and we need to eliminate left part
        if (mid % 2 == 1 && arr[mid - 1] == arr[mid] || mid % 2 == 0 && arr[mid + 1] == arr[mid]) low = mid + 1;
        // otherwise
        else high = mid - 1;
    }
    // For safety
    return arr[sz - 1];
}

int main()
{
    vector<int> v = {1,1,4,4,15};
    cout << singleNonDuplicate(v) << endl;
    return 0;
}