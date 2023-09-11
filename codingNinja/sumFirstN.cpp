#include<iostream>
using namespace std;

long long sumFirstNRec(long long n) {
    long long ab = 0;
    if (n == 1)
    {
        ab = 1;
        return ab;
    }
    ab = sumFirstNRec(n - 1);
    ab += n;
    return ab;
}

long long sumFirstN(long long n)
{
    return (n * (n + 1)) / 2;
}

int main()
{
    int n;
    cin >> n;
    cout << sumFirstN(n);
    return 0;
}