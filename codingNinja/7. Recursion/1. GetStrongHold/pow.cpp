#include<bits/stdc++.h>

using namespace std;

double helper(double x, int n) {
    if (n == 0) return 1;
    return x * helper(x, n - 1);
}

double myPow(double x, int n) {
    if (n == INT_MAX) {
        if (x == 1) return 1;
        else if (x == -1) return -1;
        else return 0;
    }
    if (n == INT_MIN) {
        if (x == 1 || x == -1) {
            return 1;
        }
        return 0;
    }
    double num = 1;
    if (n >= 0) {
        num = helper(x, n);
    } else {
        n = -n;
        num = helper(x, n);
        num = 1.0/num;
    }
    return num;
}

int main() {
    cout << "Starting Program" << endl;
    cout << myPow(0.5, 4) << endl;
    cout << myPow(2.0, -2) << endl;
    return 0;
}