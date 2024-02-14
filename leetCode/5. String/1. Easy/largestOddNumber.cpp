#include<bits/stdc++.h>

using namespace std;

string largestOddNumber(string num) {
    string ans = "";
    for (int i = num.length() - 1; i >= 0; i--)
    {
        if ((int(num[i]) - 48) % 2 == 0) {
            continue;
        } else { // 325728 -> i = 3
            ans.append(num.substr(0, i+1));
            break;
        }
    }
    return ans;
}

int main() {
    cout << "Starting Program" << endl;
    string test = "325728";
    test = largestOddNumber(test);
    cout << "Result: " << test << endl;
    return 0;
}