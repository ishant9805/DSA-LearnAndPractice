#include<bits/stdc++.h>

using namespace std;

bool rotateString(string s, string goal) {
    for(int i=0;i<=s.size();i++){
        s.push_back(s[0]);
        string temp=s.erase(0,1);
        if(s==goal){
            return true;
        }
    }
    return false;
}

int main() {
    cout << "Starting Program" << endl;
    string s = "abcde";
    string goal = "cdeab";
    cout << rotateString(s, goal) << endl;
    return 0;
}