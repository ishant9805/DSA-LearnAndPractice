#include<bits/stdc++.h>

using namespace std;

// Merge sort method
// double median(vector<int>& a, vector<int>& b) {
// 	// Write your code here.
//     int p1 = 0, p2 = 0;
//     int aSz = a.size(), bSz = b.size();
//     vector<int> tmp;
//     while (p1 < aSz && p2 < bSz)
//     {
//         if (a[p1] < b[p2]) {
//             tmp.push_back(a[p1]);
//             p1++;
//         } else {
//             tmp.push_back(b[p2]);
//             p2++;
//         }
//     }
//     while(p1 < aSz) {
//         tmp.push_back(a[p1]);
//         p1++;
//     }
//     while(p2 < bSz) {
//         tmp.push_back(b[p2]);
//         p2++;
//     }
//     int mid = (aSz + bSz) / 2;
//     if ((aSz + bSz) % 2 == 0) {
//         return (tmp[mid] + tmp[mid - 1]) / (double) 2.0;
//     }
//     else {return tmp[mid];}
// }

// Merge sort method (Modified)
// double median(vector<int>& a, vector<int>& b) {
// 	// Write your code here.
//     int p1 = 0, p2 = 0;
//     int aSz = a.size(), bSz = b.size();
//     int n = aSz + bSz;
//     int ind1 = n/2;
//     int ind2 = ind1 - 1;
//     int cnt = 0;
//     int el1 = -1, el2 = -1;
//     while (p1 < aSz && p2 < bSz)
//     {
//         if (a[p1] < b[p2]) {
//             if (cnt == ind1) el1 = a[p1];
//             if (cnt == ind2) el2 = a[p1];
//             p1++;
//             cnt++;
//         } else {
//             if (cnt == ind1) el1 = b[p2];
//             if (cnt == ind2) el2 = b[p2];
//             p2++;
//             cnt++;
//         }
//     }
//     while(p1 < aSz) {
//         if (cnt == ind1) el1 = a[p1];
//         if (cnt == ind2) el2 = a[p1];
//         p1++;
//         cnt++;
//     }
//     while(p2 < bSz) {
//         if (cnt == ind1) el1 = b[p2];
//         if (cnt == ind2) el2 = b[p2];
//         p2++;
//         cnt++;
//     }
//     int mid = (aSz + bSz) / 2;
//     if ((aSz + bSz) % 2 == 0) {
//         return (el1 + el2) / (double) 2.0;
//     }
//     return (double) el1;
// }

// Binary Search Method
double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    //if n1 is bigger swap the arrays:
    if (n1 > n2) return median(b, a);

    int n = n1 + n2; //total length
    int left = (n1 + n2 + 1) / 2; //length of left half
    //apply binary search:
    int low = 0, high = n1;
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        //calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        //eliminate the halves:
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0; //dummy statement
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {2,4,6};
    vector<int> v2 = {1,3,5};
    cout << median(v1, v2) << endl;
    vector<int> v3 = {2,4,6};
    vector<int> v4 = {1,3};
    cout << median(v3,v4) << endl;
    return 0;
}