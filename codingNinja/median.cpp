#include<bits/stdc++.h>

using namespace std;

// Merge sort method
double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
    int p1 = 0, p2 = 0;
    int aSz = a.size(), bSz = b.size();
    vector<int> tmp;
    while (p1 < aSz && p2 < bSz)
    {
        if (a[p1] < b[p2]) {
            tmp.push_back(a[p1]);
            p1++;
        } else {
            tmp.push_back(b[p2]);
            p2++;
        }
    }
    while(p1 < aSz) {
        tmp.push_back(a[p1]);
        p1++;
    }
    while(p2 < bSz) {
        tmp.push_back(b[p2]);
        p2++;
    }
    int mid = (aSz + bSz) / 2;
    if ((aSz + bSz) % 2 == 0) {
        return (tmp[mid] + tmp[mid - 1]) / (double) 2.0;
    }
    else {return tmp[mid];}
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