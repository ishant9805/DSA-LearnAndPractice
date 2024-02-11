#include<iostream>
#include<vector>
#include<numeric>
#include<bits/stdc++.h>
using namespace std;

int parts(vector<int> &vec, int maxSum) {
    int n = vec.size();
    int parts = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++)
    {
        if (subarraySum + vec[i] <= maxSum)
        {
            subarraySum += vec[i];
        } else {
            parts++;
            subarraySum = vec[i];
        }
        
    }
    return parts;
}

int largestSubarraySumMinimized(vector<int> a, int k) {
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    while(low <= high) {
        int mid =  (low + high) / 2;
        int part = parts(a, mid);
        if (part > k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> v = {1,2,3,4,5};
    cout << largestSubarraySumMinimized(v, 3) << endl;
    return 0;
}