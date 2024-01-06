#include<bits/stdc++.h>

using namespace std;

// Using merge sort algo
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    int p1 = 0, p2 = 0;
    int index = 0;
    while (p1 < n && p2 < m) {
        if (arr1[p1] < arr2[p2]) {
            p1++;
            index++;
            if (index == k) {
                return arr1[p1];
            }
        } else {
            p2++;
            index++;
            if (index == k) {
                return arr2[p2];
            }
        }
    }
    while (p1 < n) {
        p1++;
        index++;
        if (index == k) {
            return arr1[p1];
        }
    }
    while (p2 < m) {
        p2++;
        index++;
        if (index == k) {
            return arr2[p2];
        }
    }
    return -1;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {2,3,45};
    vector<int> v2 = {4,6,7,8};
    cout << kthElement(v1, v2, v1.size(), v2.size(), 4) << endl;
    return 0;
}