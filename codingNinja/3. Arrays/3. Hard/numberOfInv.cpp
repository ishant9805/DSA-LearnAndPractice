#include<iostream>
#include<vector>
using namespace std;

// Brute force approach
// int numberOfInversions(vector<int>&a, int n) {
//     // Write your code here.
//     int res = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             if (i < j && a[i] > a[j])
//             {
//                 res++;
//             }
            
//         }
        
//     }
//     return res;
// }

int cnt = 0;
// Using Merge sort algo
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        // left is smaller
        if (arr[left] <= arr[right])
        {
            // push the left(smaller) element into temp
            temp.push_back(arr[left]);
            left++;
        } // right is smaller 
        else {
            // push the right(smaller) element into temp
            cnt += (mid - left + 1);
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if any element left in the left part of array
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    // if any element left in the right part of array
    // right part was written later because each element in left is smaller than right
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    // pushing the sorted array of temp into original array
    for (int i = low; i <= high; i++)
    {
        // low is being subtracted because temp contains the sorted array which
        // is a part of whole array.
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid); // left part
    mergeSort(arr, mid + 1, high); // right part
    merge(arr, low, mid, high); // merging both left and right
}

int numberOfInversions(vector< int > v, int sz) {
    mergeSort(v, 0, sz - 1);
    return cnt;
}

int main()
{
    vector<int> v = {5,3,2,1,4};
    int k = numberOfInversions(v, v.size());
    cout << "K: " << k << endl;
    return 0;
}