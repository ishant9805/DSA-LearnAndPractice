#include<bits/stdc++.h>

using namespace std;

int romanToInt(string s) {
    int res = 0;
    unordered_map<char, int> ump = {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
    };
    int prev = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        int curr = ump[s[i]];
        if (prev <= curr) {
            res += curr;
        } else {
            res -= curr;
        }
        prev = curr;
    }
    return res;
}

int main() {
    cout << "Starting Program" << endl;
    string s = "MCMXCIV";
    cout << romanToInt(s) << endl;
    
    return 0;
}