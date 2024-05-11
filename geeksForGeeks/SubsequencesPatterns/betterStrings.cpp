#include<bits/stdc++.h>

using namespace std;

unordered_set<string> subseq(int k, string s, string newS, int n, unordered_set<string> v) {
    // base case
    if (k == n) {
        v.insert(newS);
        return v;
    }
    // pick
    newS.push_back(s[k]);
    v = subseq(k+1, s, newS, n, v);
    newS.pop_back();
    // don't pick
    v = subseq(k+1, s, newS, n, v);
    return v;
}

string betterString(string str1, string str2) {
    unordered_set<string> s;
    s = subseq(0, str1, "", str1.length(), s);

    unordered_set<string> s2;
    s2 = subseq(0, str2, "", str2.length(), s2);

    if (s.size()>=s2.size()) return str1;
    return str2;
}

int main() {
    cout << "Starting Program" << endl;
    string s1 = "gfg";
    cout << betterString(s1, "ggg") << endl;
    return 0;
}