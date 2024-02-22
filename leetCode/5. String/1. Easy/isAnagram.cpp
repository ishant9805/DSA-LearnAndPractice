#include<bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length()) return false;
    map<char, int> s1, s2;
    for (int i = 0; i < s.length(); i++)
    {
        if (s1.find(s[i]) != s1.end())
        {
            s1[s[i]]++;
        } else {
            s1.insert(make_pair(s[i], 1));
        }
    }
    for (int i = 0; i < t.length(); i++)
    {
        if (s2.find(t[i]) != s2.end())
        {
            s2[t[i]]++;
        } else {
            s2.insert(make_pair(t[i], 1));
        }
    }
    for (auto itr = s1.begin(); itr != s1.end(); ++itr) {
      auto ss = s2.find(itr->first);
      if (ss == s2.end()) return false;
      if (ss->second != itr->second) return false;
    }
    
    for (auto itr = s2.begin(); itr != s2.end(); ++itr) {
      auto ss = s1.find(itr->first);
      if (ss == s1.end()) return false;
      if (ss->second != itr->second) return false;
    }
    return true;
}

int main() {
    cout << "Starting Program" << endl;
    string a = "listen";
    string b = "silent";
    cout << isAnagram(a, b) << endl;
    a = "rasp", b = "spaz";
    cout << isAnagram(a, b) << endl;
    return 0;
}