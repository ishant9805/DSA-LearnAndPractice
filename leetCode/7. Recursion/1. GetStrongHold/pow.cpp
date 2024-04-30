#include<bits/stdc++.h>

using namespace std;

double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) {
        n = -1 * n;
        return 1 / (x * myPow(x, n - 1));
    }
    return x * myPow(x, n - 1);
}

int main() {
    cout << "Starting Program" << endl;
    cout << myPow(0.5, 4) << endl;
    cout << myPow(0.5, -4) << endl;
    return 0;
}