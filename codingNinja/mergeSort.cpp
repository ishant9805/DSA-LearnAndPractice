#include<iostream>
#include<vector>
using namespace std;

// Vectorial Solution

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // Merging remaining elems
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Rearranging main array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
        
}

void mergeSort(vector<int>& arr, int low, int high) {
    // Base Case
    if (low >= high)
    {
        return;
    }
    // Middle of array calc
    int mid = (low + high) / 2;
    // Dividing
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    // Merge
    merge(arr, low, mid, high);
}

int main()
{
    vector<int> arr = {9, 3, 6, 2, 0};
    mergeSort(arr, 0, arr.size() - 1);
    cout << "[";
    for (int i = 0; i < arr.size() - 1; i++)
    {
       cout << arr[i] << ", ";
    }
    cout << arr[arr.size() - 1] << "]" << endl;
    return 0;
}

// Array Form
// void merge(int arr[], int l, int mid, int r)
// {
//     int *tmp = new int[r+1];
//     int left = l;
//     int right = mid + 1;
//     int i = 0;
//     while (left <= mid && right <= r && i <= r)
//     {
//         if (arr[left] <= arr[right]) {
//             tmp[i] = arr[left];
//             left++;
//         }
//         else {
//             tmp[i] = arr[right];
//             right++;
//         }
//         i++;
//     }
//     while (left <= mid && i <= r)
//     {
//         tmp[i] = arr[left];
//         left++;
//         i++;
//     }
//  
//     while (right <= r && i <= r)
//     {
//         tmp[i] = arr[right];
//         right++;
//         i++;
//     }
//
//     for (int k = l; k <= r; k++)
//     {
//         arr[k] = tmp[k - l];
//     }
//  
//     cout << "[";
//     for (int i = 0; i < r; i++)
//     {
//        cout << tmp[i] << ", ";
//     }
//     cout << tmp[r] << "]" << endl;
// }

// void mergeSort(int arr[], int l, int r) {
//     // Write Your Code Here
//     if (l >= r)
//     {
//         return;
//     }
//
//     int mid = (l + r) / 2;
//     mergeSort(arr, l, mid);
//     mergeSort(arr, mid + 1, r);
//     merge(arr, l, mid, r);
// }

// int main()
// {
//     // int arr[7] = {2, 13, 4, 1, 3, 6, 28}; // {2, 4, 5, 7, 9}
//     int arr[5] = {9, 3, 6, 2, 0}; // {2, 4, 5, 7, 9}
//     mergeSort(arr, 0, 4);
//     cout << "[";
//     for (int i = 0; i < 4; i++)
//     {
//        cout << arr[i] << ", ";
//     }
//     cout << arr[4] << "]" << endl;
//     return 0;
// }