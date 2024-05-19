#include<bits/stdc++.h>

using namespace std;

void helper(int target, vector<vector<int>> &res, vector<int> &currSum, int ind, int k) {
    if (target == 0) {
        if (currSum.size() == k) res.push_back(currSum);
        return;
    }
    
    for (int i = ind; i < 10; i++) {
        if (i > target) break;
        if (currSum.size() >= k) return;
        currSum.push_back(i);
        helper(target - i, res, currSum, i + 1, k);
        currSum.pop_back();
    }
    return;
}


vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> currSum;
    vector<vector<int>> ans;
    helper(n, ans, currSum, 1, k);
    return ans;
}

int main() {
    cout << "Starting Program" << endl;
    vector<vector<int>> v1 = combinationSum3(3, 7);
    for(auto it: v1) {
        cout << "{ ";
        for(auto iter: it) {
            cout << iter << " ";
        }
        cout << "}";
    }
    cout << endl;
    return 0;
}