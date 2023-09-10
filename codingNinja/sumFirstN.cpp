#include<iostream>
using namespace std;

long long sumFirstN(long long n) {
    long long ab = 0;
    if (n == 1)
    {
        ab = 1;
        return ab;
    }
    ab = sumFirstN(n - 1);
    ab += n;
    return ab;
}

int main()
{
    int n;
    cin >> n;
    cout << sumFirstN(n);
    return 0;
}