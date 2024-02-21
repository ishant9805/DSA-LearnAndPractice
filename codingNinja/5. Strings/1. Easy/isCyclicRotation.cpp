#include<bits/stdc++.h>

using namespace std;

int isCyclicRotation(string &p, string &q) 
{
    if (p.length()!=q.length()) return false;
    p = p + p;
    return (p.find(q) != -1) ? 1 : 0;
}

int main() {
    cout << "Starting Program" << endl;
    string p = "abfyg";
    string q = "gabfy";
    int k = isCyclicRotation(p, q);
    return 0;
}