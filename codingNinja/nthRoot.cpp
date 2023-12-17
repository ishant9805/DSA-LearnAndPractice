#include<iostream>
#include<vector>

using namespace std;

// Linear checks
int NthRoot(int n, int m) {
    for (int i = 0; i < m; i++)
    {
        long long val = pow(i, n);
        if (val == m) {
            return i;
        } else if (val > m) {
            break;
        }
    }
    return -1;
}

int main()
{
    cout << NthRoot(3, 27) << endl;
    cout << NthRoot(4, 69) << endl;
    cout << NthRoot(9, 1953125) << endl;
    // cout << pow(3,4) << endl;
    return 0;
}