#include<bits/stdc++.h>

using namespace std;

string lstrip(string word) {
    if (word.size() == 0) {
        return word;
    }
    if (word[0] == ' ') {
        word = word.substr(1);
        return lstrip(word);
    }
    return word;
}

int helper(string s) {
    if(s.size() == 0 || !isdigit(s[0])) return 0;
    int ans = s[0] - '0';
    s = s.substr(1);
    int x = helper(s);

}

int createAtoi(string s) {
    int len = s.length();
    if (len == 0) return 0;
    s = lstrip(s);
    int sign = 1;
    long ans = 0;
    if (s[0] == '-') {
        sign = -1;
        s = s.substr(1);
    } else if (s[0] == '+') {
        s = s.substr(1);
    }
    ans = helper(s);
}

int main() {
    cout << "Starting Program" << endl;
    string wo = "  ishant  ";
    cout << wo << endl;
    wo = lstrip(wo);
    cout << wo << endl;
    return 0;
}