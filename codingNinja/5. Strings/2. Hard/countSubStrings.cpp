#include<bits/stdc++.h>

using namespace std;

int countSubStrings(string str, int k) 
{
    int len = str.length();
    int res = 0;
    int cnt[26]; // Array for hashing
    for (int i = 0; i < len; i++) {
        int distCnt = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int j = i; j < len; j++)
        {
            if (cnt[str[j] - 'a'] == 0) {
                distCnt++;
            }
            cnt[str[j] - 'a']++;
            if (distCnt == k) {
                res++;
            }
        }
    }
    return res;
}

int main() {
    cout << "Starting Program" << endl;
    string example = "aacfssa";
    cout << countSubStrings(example, 3) << endl;
    return 0;
}