#include<iostream>
#include<vector>

using namespace std;

// Linear checks
// int NthRoot(int n, int m) {
//     for (int i = 0; i < m; i++)
//     {
//         long long val = pow(i, n);
//         if (val == m) {
//             return i;
//         } else if (val > m) {
//             break;
//         }
//     }
//     return -1;
// }

// Binary search
int powe(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 0;
    }
    if (ans == m) return 1;
    return 2;
}

int NthRoot(int n, int m) {
    int l = 1, h = m;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        int res = powe(mid, n, m);
        if (res == 1) return mid;
        else if (res == 0) h = mid - 1;
        else l = mid + 1;
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