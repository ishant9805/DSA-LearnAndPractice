#include<bits/stdc++.h>

using namespace std;

int maxDepth(string s) {
    int d = 0;
    int maxD = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        char tmp = s[i];
        switch (tmp)
        {
        case '(':
            d++;
            break;
        case ')':
            if (d > maxD) maxD = d;
            d--;
            break;
        default:
            break;
        }
    }
    return maxD;
}

int main() {
    cout << "Starting Program" << endl;
    string s = "(1+(2*3)+((8)/4))+1";
    cout << maxDepth(s) << endl;    
    return 0;
}