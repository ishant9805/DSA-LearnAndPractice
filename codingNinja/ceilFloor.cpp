#include<iostream>
#include<vector>

using namespace std;

// Brute Force approach
// pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
// 	// Write your code here.
//     int ceil = -1;
//     int flr = -1;
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] >= x)
//         {
//             ceil = a[i];
//             break;
//         }        
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] <= x)
//         {
//             flr = a[i];
//         }        
//     }
//     return {flr, ceil};
// }

// Optimal approach
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	pair<int, int> ans = {-1 , -1};
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == x)
        {
            ans.first = a[mid];
            ans.second = a[mid];
            return ans;
        } else if (a[mid] < x) {
            low = mid + 1;
            ans.first = a[mid];
        } else {
            high = mid - 1;
            ans.second = a[mid];
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {3,4,7,8,8,10};
    pair<int, int> k = getFloorAndCeil(v, v.size(), 5);
    cout << "pair<" << k.first << ", " << k.second << ">" << endl;
    k = getFloorAndCeil(v, v.size(), 8);
    cout << "pair<" << k.first << ", " << k.second << ">" << endl;
    v = {2};
    k = getFloorAndCeil(v, v.size(), 23);
    cout << "pair<" << k.first << ", " << k.second << ">" << endl;
    return 0;
}