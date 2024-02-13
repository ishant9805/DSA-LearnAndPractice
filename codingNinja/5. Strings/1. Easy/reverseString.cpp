#include<bits/stdc++.h>

using namespace std;

string reverseString(string &str){
	// Write your code here.
    string sentence = "";
    int length = str.length();
    int count = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        if (str[i] == ' ' && count != 0) {
            sentence.append(str.substr(i+1, count));
            sentence.push_back(' ');
            count = 0;
        } else if (str[i] == ' ' && count == 0) {
            continue;
        } else if (i == 0) {
            sentence.append(str.substr(0, str.find(' ')));
        } else {
            count++;
        }
        // "I am a star"
        //   1  4 5    
    }
    return sentence;
}

int main() {
    cout << "Starting Program" << endl;
    string name = "   m rs   x       JmkL       ";
    name = reverseString(name);
    cout << name << endl;
    // cout << "Result: " << name.substr(5,5) << endl;
    return 0;
}