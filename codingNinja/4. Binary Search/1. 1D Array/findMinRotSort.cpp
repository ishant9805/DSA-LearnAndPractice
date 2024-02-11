#include<iostream>
#include<vector>

using namespace std;

// Brute force method
// int findMin(vector<int>& arr) {
// 	int min = 1e9;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (min > arr[i])
//         {
//             min = arr[i];
//         }
        
//     }
//     return min;
// }

// BS method
int findMin(vector<int>& arr){
	int ans = 1e9, low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        // if left part is sorted
        if (arr[low] <= arr[mid]) {
            // the first element of sorted arr would be min of that part
            if (arr[low] < ans) {
                ans = arr[low];
            }
            // Ignore the sorted array
            low = mid + 1;
        } // if right part is sorted
        else if (arr[mid] <= arr[high]) {
            // the first element of sorted arr would be min of that part
            if (arr[mid] < ans) {
                ans = arr[mid];
            }
            // Ignore the sorted array
            high = mid - 1;
        }
        // Again check min on unsorted part of array
    }
    return ans;
}
int main()
{
    vector<int> v = {3, 4, 1, 2};
    cout << findMin(v) << endl;
    v = {4,5,6,7,0,1,2};
    cout << findMin(v) << endl;
    return 0;
}