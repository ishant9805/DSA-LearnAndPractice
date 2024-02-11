#include<bits/stdc++.h>

using namespace std;

// Using merge sort algo
// int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
//     int p1 = 0, p2 = 0;
//     int index = 0;
//     while (p1 < n && p2 < m) {
//         if (arr1[p1] < arr2[p2]) {
//             index++;
//             if (index == k) {
//                 return arr1[p1];
//             }
//             p1++;
//         } else {
//             index++;
//             if (index == k) {
//                 return arr2[p2];
//             }
//             p2++;
//         }
//     }
//     while (p1 < n) {
//         index++;
//         if (index == k) {
//             return arr1[p1];
//         }
//         p1++;
//     }
//     while (p2 < m) {
//         index++;
//         if (index == k) {
//             return arr2[p2];
//         }
//         p2++;
//     }
//     return -1;
// }

// Using Binary Search
int kthElement(vector<int> arr1, vector<int> arr2, int m, int n, int k) {
    if (m > n) return kthElement(arr2, arr1, n, m, k);
    int low = max(0, k - m), high = min(k, n);
    while (low <= high) {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;
        int l1 = cut2 <= 0 ? INT_MIN : arr1[cut2 - 1];
        int l2 = cut1 == 0 ? INT_MIN : arr2[cut1 - 1];
        int r1 = cut2 == n ? INT_MAX : arr1[cut2];
        int r2 = cut1 == m ? INT_MAX : arr2[cut1];
        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if (l1 > l2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }
    return 1;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v3 = {1,2,3,5,6};
    vector<int> v4 = {4,7,8,9,100};
    cout << kthElement(v3, v4, v3.size(), v4.size(), 6) << endl;
    return 0;
}