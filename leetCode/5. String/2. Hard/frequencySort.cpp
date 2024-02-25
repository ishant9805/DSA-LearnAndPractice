#include<bits/stdc++.h>

using namespace std;

// Solution Video :- https://youtu.be/msSEO2mxOyk?feature=shared

string frequencySort(string& s)
{
    unordered_map<char, int> mpp;
    priority_queue<pair<int, char>> pq;
    string res = "";
    for (char ch:s)
    {
        mpp[ch]++;
    }
    for (auto it:mpp) {
        pq.push({it.second, it.first});
    }
    while (!pq.empty())
    {
        auto tmp = pq.top();
        int fq = tmp.first;
        char ch = tmp.second;
        res += string(fq, ch);
        pq.pop();
    }
    return res;
}


int main() {
    cout << "Starting Program" << endl;
    string s = "tree";
    s = frequencySort(s);
    cout << s << endl;
    
    return 0;
}