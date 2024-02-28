#include<bits/stdc++.h>

using namespace std;

int createAtoi(string s) {
    bool flag = false;
    int res = 0;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (flag && ((int) (s[i]) >= 48 && (int) (s[i]) <= 57))
        {
            
        }
        
    }
    
}

int main() {
    cout << "Starting Program" << endl;
    string s = "45rohit12";
    cout << createAtoi(s) << endl;
    return 0;
}