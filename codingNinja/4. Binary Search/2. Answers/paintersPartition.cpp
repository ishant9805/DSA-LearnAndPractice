#include<bits/stdc++.h>

using namespace std;

int parts(vector<int> &vec, int maxArea) {
    int sz = vec.size();
    int prt = 1;
    long long area = 0;
    for (int i = 0; i < sz; i++)
    {
        if (area + vec[i] <= maxArea) {
            area += vec[i];
        } else {
            area = vec[i];
            prt++;
        }
    }
    return prt;
}

int findLargestMinDistance(vector<int> &boards, int k){
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int res = parts(boards, mid);
        if (res <= k)
        {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    cout << "Starting Program" << endl;
    // vector<int> v1 = {2,1,5,6,2,3};
    // cout << findLargestMinDistance(v1, 2) << endl;
    // vector<int> v2 = {10,20,30,40};
    // cout << findLargestMinDistance(v2, 2) << endl;
    vector<int> v3 = {8,6,10,3,2,7,10};
    cout << findLargestMinDistance(v3, 7) << endl;
    return 0;
}