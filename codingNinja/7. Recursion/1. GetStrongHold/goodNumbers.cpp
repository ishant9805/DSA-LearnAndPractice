#include<bits/stdc++.h>

using namespace std;

bool helper(int x, int digit, int sum) {
    if (x == 0) return true;
    int last = x % 10;
    if (last > sum && last != digit) {
        sum += last;
        return helper(x/10, digit, sum);
    }
    return false;
}

vector<int> goodNumbers(int a, int b, int digit) {
	vector<int> ans;
    for (int i = a; i <= b; i++) {
        if (i % 10 == digit) continue;
        if (helper(i/10, digit, i%10)) ans.push_back(i);
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