#include<bits/stdc++.h>

using namespace std;

string sortByFrequency(int n, string& s)
{
	map<char, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[s[i]]++;
    }
    string res = "";
    for (auto itr = mpp.begin(); itr != mpp.end(); ++itr) {
        res.insert(0, itr->second, itr->first);
    }
    return res;
}


int main() {
    cout << "Starting Program" << endl;
    string s = "abcAbc";
    s = sortByFrequency(s.length(), s);
    cout << s << endl;
    
    return 0;
}