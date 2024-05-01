#include<bits/stdc++.h>

using namespace std;

bool helper(int x, int digit) {
    if (x == digit) return false;
    if (x < 10) return true;
    if (x%10 != digit && x%10 < (x % 100)/10) {
        return helper(x/10, digit);
    }
    return false;
}

vector<int> goodNumbers(int a, int b, int digit) {
	vector<int> ans;
    for (int i = a; i <= b; i++) {
        if (helper(i, digit)) ans.push_back(i);
    }
    return ans;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v = goodNumbers(20, 45, 1);
    cout << "------Printing Vector------\nVector: {";
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "}" << endl;
    return 0;
}