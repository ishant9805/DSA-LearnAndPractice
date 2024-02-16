#include<bits/stdc++.h>

using namespace std;

bool areIsomorphic(string &str1, string &str2) {
    map<char, char> mapp;
    map<char, char> revMapp;
    for (int i = 0; i < str1.length(); i++)
    {
        if (((mapp.find(str1[i]) != mapp.end()) && (mapp[str1[i]] != str2[i])) ||
            ((revMapp.find(str2[i]) != revMapp.end()) && (revMapp[str2[i]] != str1[i]))){
            return false;
        }
        mapp.insert(make_pair(str1[i], str2[i]));
        revMapp.insert(make_pair(str2[i], str1[i]));
    }
    
    return true;
}

int main() {
    cout << "Starting Program" << endl;
    string str1 = "hgvoo";
    string str2 = "bnnff";
    cout << areIsomorphic(str1, str2) << endl;
    str1 = "aab";
    str2 = "xyz";
    cout << areIsomorphic(str1, str2) << endl;
    return 0;
}