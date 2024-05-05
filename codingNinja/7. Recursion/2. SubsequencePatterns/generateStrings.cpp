#include<bits/stdc++.h>

using namespace std;

vector<string> generateString(int N) {
    if (N == 0) return {};
    if (N == 1) {
        return {"0", "1"};
    }
    vector<string> ans = generateString(N-1);
    vector<string> res;
    for (int i = 0; i < ans.size(); i++) {
        string ith = ans[i];
        res.push_back(ith += '0');
        if (ans[i].back() != '1') {
            res.push_back(ans[i] += '1');
        }
    }
    return res;
}

int main() {
    cout << "Starting Program" << endl;
    vector<string> v1 = generateString(4);
    cout << "------Printing Vector------\nVector: {";
    for (int i = 0; i < v1.size() - 1; i++)
    {
        cout << v1[i] << ", ";
    }
    cout << v1[v1.size() - 1] << "}" << endl;    
    return 0;
}