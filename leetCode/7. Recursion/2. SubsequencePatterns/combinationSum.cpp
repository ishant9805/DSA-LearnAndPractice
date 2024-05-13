#include<bits/stdc++.h>

using namespace std;

void helper(int ind,vector<int> &candidates, vector<int> &store, vector<vector<int>> &res, int target) {
    // Base Case
    if (ind == candidates.size()) {
        if (target == 0) {
            res.push_back(store);
        }
        return;
    }
    // Pick
    if (candidates[ind] <= target) {
        store.push_back(candidates[ind]);
        helper(ind,candidates, store, res, target - candidates[ind]);
        store.pop_back();
    }
    // Don't Pick
    helper(ind + 1,candidates, store, res, target);
    
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ds;
    vector<int> v;
    helper(0, candidates, v, ds, target);
    return ds;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v = {2,3,6,7};
    vector<vector<int>> v1 = combinationSum(v, 7);
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