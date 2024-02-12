#include<bits/stdc++.h>

using namespace std;

string removeOuterParentheses(string s) {
    // s.erase(s.begin() + 2);
    int len = s.length();
    int cnt = 0;
    int index = 0;
    bool st = false;
    for (int i = 0; i < len; i++)
    {
        switch (s[i])
        {
        case '(':
            if (!st) {
                index = i;
                st = true;
            }
            cnt++;
            break;
        
        case ')':
            cnt--;
            if (cnt == 0 && st) {
                s.erase(s.begin()+index);
                s.erase(s.begin() + i);
                i -= 2;
                index = 0;
            }
        }
    }
    
    return s;
}


int main() {
    cout << "Starting Program" << endl;
    string s = "(()())(())";
    s = removeOuterParentheses(s);
    cout << "After removal: " << s << endl;
    
    return 0;
}