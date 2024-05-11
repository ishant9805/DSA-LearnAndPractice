#include<bits/stdc++.h>

using namespace std;

int helper(int arr[], vector<int> &ds, int n, int sum, int s, int ind) {
    if (ind == n) {
        if (s == sum) return 1;
        return 0;
    }
    // pick
    ds.push_back(arr[ind]);
    s += arr[ind];

    int l = helper(arr, ds, n, sum, s, ind + 1);

    ds.pop_back();
    s -= arr[ind];

    // don't pick
    int r = helper(arr, ds, n, sum, s, ind + 1);

    return l + r;
}

int perfectSum(int arr[], int n, int sum) {
    vector<int> ds;
    return helper(arr, ds, n, sum, 0, 0);
}

int main() {
    cout << "Starting Program" << endl;
    int arr[] = {5,2,3,10,6,8};
    cout << perfectSum(arr, 6, 10) << endl;
    
    return 0;
}