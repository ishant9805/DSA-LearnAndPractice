#include<bits/stdc++.h>

using namespace std;

vector<string> generateSubsequences(string s)
{
    vector<string> res;
    int n = s.length();
    for (int i = 0; i < (1<<n); i++) {
        string str = "";
        for (int j = 0; j < n; j++) {
            // & = AND operator not binary comparison operator
            if (i & (1<<j)) {
                str += s[j];
            }
        }
        res.push_back(str);
    }
    return res;
}

int main() {
    cout << "Starting Program" << endl;
    vector<string> v1 = generateSubsequences("abc");
    cout << "------Printing Vector------\nVector: {";
    for (int i = 0; i < v1.size() - 1; i++)
    {
        cout << v1[i] << ", ";
    }
    cout << v1[v1.size() - 1] << "}" << endl;
    return 0;
}