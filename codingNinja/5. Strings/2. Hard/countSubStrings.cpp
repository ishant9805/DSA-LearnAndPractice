#include<bits/stdc++.h>

using namespace std;

int countSubStrings(string str, int k) 
{
    return str.length() - k;
}

int main() {
    cout << "Starting Program" << endl;
    string example = "aacfssa";
    cout << countSubStrings(example, 3) << endl;
    return 0;
}