#include<bits/stdc++.h>

using namespace std;

void helper(int target, vector<vector<int>> &res, vector<int> &candidates, vector<int> &currSum, int ind) {
    if (target == 0) {
        res.push_back(currSum);
        return;
    }
    
    for (int i = ind; i < candidates.size(); i++) {
        if (i > ind && candidates[i] == candidates[i-1]) continue;
        if (candidates[i] > target) break;
        currSum.push_back(candidates[i]);
        helper(target - candidates[i], res, candidates, currSum, i + 1);
        currSum.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> currSum;
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    helper(target, ans, candidates, currSum, 0);
    return ans;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v = {14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12};
    vector<vector<int>> v1 = combinationSum2(v, 27);
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