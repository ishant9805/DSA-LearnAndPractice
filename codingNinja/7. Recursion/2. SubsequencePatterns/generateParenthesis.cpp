#include<bits/stdc++.h>

using namespace std;

void helper(int n, int openC, int closeC, vector<string> &v, string s) {
    if (openC == closeC && openC == n) {
        v.push_back(s);
        return;
    }
    if (openC < n) {
        helper(n, openC+1, closeC, v, s+"(");
    }
    if (closeC < openC) {
        helper(n, openC, closeC + 1, v, s+")");
    }
}

vector<string> validParenthesis(int n) {
    vector<string> v;
    helper(n, 0, 0, v, "");
    return v;
}

int main() {
    cout << "Starting Program" << endl;
    vector<string> v1 = validParenthesis(3);
    cout << "------Printing Vector------\nVector: {";
    for (int i = 0; i < v1.size() - 1; i++)
    {
        cout << v1[i] << ", ";
    }
    cout << v1[v1.size() - 1] << "}" << endl;
    
    return 0;
}