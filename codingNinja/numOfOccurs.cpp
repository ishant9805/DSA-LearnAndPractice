#include<iostream>
#include<vector>

using namespace std;

// Brute force approach
// int count(vector<int> &arr, int n, int x) {
//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == x)
//         {
//             cnt++;
//         }
        
//     }
//     return cnt;
// }

// BS approach
int count(vector<int>& arr, int n, int x) {
	int low = 0, high = n - 1;
    int ocrLast = -1;
    // Last occurence
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            ocrLast = mid;
            low = mid + 1;
        } else if (arr[mid] > x)
        {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    // First Occurence
    int ocrFst = -1;
    low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ocrFst = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        
    }
    if (ocrLast == -1) return 0;
    return ocrLast - ocrFst + 1;
}

int main()
{
    vector<int> v = {1,1,1,2,2,3,3};
    int k = count(v, v.size(), 3);
    cout << k << endl;
    return 0;
}