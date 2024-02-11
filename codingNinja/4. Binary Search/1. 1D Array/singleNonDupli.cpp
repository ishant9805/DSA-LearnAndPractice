#include<iostream>
#include<vector>

using namespace std;

// Brute Force
// int singleNonDuplicate(vector<int>& arr) {
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (arr[i - 1] == arr[i] || arr[i] == arr[i + 1]) continue;
//         else return arr[i];
//     }
//     return arr[0];   
// }

// Binary Search
int singleNonDuplicate(vector<int>& arr) {
	int sz = arr.size();
    if (sz == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[sz - 2] != arr[sz - 1]) return arr[sz - 1];
    int low = 1, high = sz - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) return arr[mid];
        if (mid % 2 == 1 && arr[mid - 1] == arr[mid] || mid % 2 == 0 && arr[mid + 1] == arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return arr[sz - 1];
}

int main()
{
    vector<int> v = {1,1,4,4,15};
    cout << singleNonDuplicate(v) << endl;
    return 0;
}