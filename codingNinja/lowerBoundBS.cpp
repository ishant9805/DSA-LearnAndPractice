#include<iostream>
#include<vector>

using namespace std;
// Brute force approach
// int lowerBound(vector<int> arr, int n, int x) {
// 	for (int i = 0; i < n; i++)
//     {
//         if (arr[i] >= x)
//         {
//             return i;
//         }
        
//     }
//     return n;
// }

// BSearch Method
int lowerBound(vector<int> arr, int n, int x) {
    int ans = n;
    int low = 0, high = n -1;
    int mid = (low + high) / 2;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            high = mid;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }
    return ans;

}

int main()
{
    vector<int> v = {1,2,2,3,3,5};
    int k = lowerBound(v, v.size(), 0);
    cout << k << endl;
    k = lowerBound(v, v.size(), 2);
    cout << k << endl;
    k = lowerBound(v, v.size(), 6);
    cout << k << endl;
    return 0;
}