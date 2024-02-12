#include<bits/stdc++.h>

using namespace std;

int maxDepth(string s) {
	int sz = s.length();
    int maxTill = 0;
    int pOCnt = 0;
    for (int i = 0; i < sz; i++) {
        switch (s[i])
        {
        case '(':
            pOCnt++;
            maxTill = max(maxTill, pOCnt);
            break;
        
        case ')':
            pOCnt--;
        }
    }
    return maxTill;
}


int main() {
    cout << "Starting Program" << endl;
    string s = "1+(3*6+(9-3))";
    cout << "Max Depth: " << maxDepth(s) << endl;
    
    return 0;
}