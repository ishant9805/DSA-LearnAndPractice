#include<iostream>
#include<vector>

using namespace std;

// Brute Force
// int findNum(vector<int> v, int l) {
//     int low = 0, high = v.size() - 1;
//     while (low <= high)
//     {
//         int mid = (low + high) / 2;
//         if (v[mid] == l) return mid;
//         else if (v[mid] < l) {
//             low = mid + 1;
//         } else {
//             high = mid - 1;
//         }
//     }
//     return -1;
// }
// int missingK(vector < int > vec, int n, int k) {
//     int cnt = 0;
//     int maxi = vec[n - 1];
//     for (int i = 1; i < maxi; i++)
//     {
//         if (findNum(vec, i) == -1)
//         {
//             cnt++;
//         }
//         if (cnt == k)
//         {
//             return i;
//         }   
//     }
//     return maxi+(k-cnt);
// }
// Binary search
int missingK(vector<int> v, int n, int k) {
    int low = 0, high = n - 1;
    while (low <=  high) {
        int mid = (low + high) / 2;
        // finding no. of missed ints till mid
        int missed = v[mid] - (mid + 1);
        if (missed < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    // vec[high] stores the greatest integer lesser
    // than kth missing num present in vector
    // thus no. of missed nums till vec[high], missNum = vec[high] - (high + 1)
    // therefore, kth missed num = vec[high] + k - missNum = k + high + 1;
    return k + high + 1;
}

int main()
{
    vector<int> v = {4,7,9,10};
    cout << missingK(v, 4, 4) << endl;
    return 0;
}