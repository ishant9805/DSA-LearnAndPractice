#include<bits/stdc++.h>

using namespace std;

int myAtoi(string s) {
    int len = s.length();
    if (len == 0) return 0;
    int i = 0;
    while (i < len && s[i] == ' ')
    {
        i++;
    }
    s = s.substr(i);
    int sign = +1;
    long ans = 0;
    if (s[0] == '-') sign = -1;
    int max = INT_MAX, min = INT_MIN;
    i = (s[0] == '-' || s[0] == '+') ? 1 : 0;
    while (i < len)
    {
        if (s[0] == ' ' || !isdigit(s[i])) break;
        ans = ans * 10 + s[i] - '0';
        if (sign == -1 && sign * ans < min) return min;
        if (sign == 1 && sign * ans > max) return max;
        i++;
    }
    ans = (int)(sign*ans);
    return ans;
}

int main() {
    cout << "Starting Program" << endl;
    string s = "45rohit12";
    cout << myAtoi(s) << endl;
    s = "   -72xyz";
    cout << myAtoi(s) << endl;
    return 0;
}