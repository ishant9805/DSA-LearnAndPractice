#include<bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int aSz = nums1.size(), bSz = nums2.size();
    // Assume nums1 is smaller and swap if it's not.
    if (aSz > bSz) return findMedianSortedArrays(nums2, nums1);
    int total_len = aSz + bSz;
    int half = (total_len + 1) / 2;
    int low = 0, high = aSz;
    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = half - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < aSz) r1 = nums1[mid1];
        if (mid2 < bSz) r2 = nums2[mid2];
        if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
        if (l1 <= r2 && l2 <= r1) {
            if (total_len % 2 == 1) return max(l1,l2);
            else return ((double) (max(l1, l2) + min(r1, r2))) / 2.0;
        }
        // Eliminations
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1,3};
    vector<int> v2 = {2};
    cout << findMedianSortedArrays(v1, v2) << endl;
    return 0;
}