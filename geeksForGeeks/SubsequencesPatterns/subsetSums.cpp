#include<bits/stdc++.h>

using namespace std;

void helper(int index, vector<int> &arr, vector<int> &sums, int currSum) {
    if (index == arr.size()) {
        sums.push_back(currSum);
        return;
    }

    currSum += arr[index];
    helper(index + 1, arr, sums, currSum);
    currSum -= arr[index];

    helper(index + 1, arr, sums, currSum);
    return;
}

vector<int> subsetSums(vector<int> arr, int n) {
    vector<int> sums;
    helper(0, arr, sums, 0);
    sort(sums.begin(), sums.end());
    return sums;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {5,2,1};
    v1 = subsetSums(v1, v1.size());
    for (auto it : v1) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}