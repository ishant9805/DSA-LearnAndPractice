#include<bits/stdc++.h>

using namespace std;

string join(vector<string> s) {
    string answer;
    int to = s.size() - 1;
    for (int i = 0; i < to; i++)
    {
        answer.append(s[i]);
        answer.append(" ");
    }
    answer.append(s[to]);
    return answer;
}

string reverseWords(string str) {
	// Write your code here.
    vector<string> sentence;
    int length = str.length();
    int count = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        if (str[i] == ' ' && count != 0) {
            sentence.push_back(str.substr(i+1, count));
            count = 0;
        } else if (str[i] == ' ' && count == 0) {
            continue;
        } else if (i == 0) {
            sentence.push_back(str.substr(0, str.find(' ')));
        } else {
            count++;
        }
        // "  hello world  "
        //   1  4 5    
    }
    str = join(sentence);
    return str;
}

int main() {
    cout << "Starting Program" << endl;
    string name = "  hello world  ";
    name = reverseWords(name);
    cout << name << endl;
    // cout << "Result: " << name.substr(5,5) << endl;
    return 0;
}