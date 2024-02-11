#include<iostream>
using namespace std;

long reverseBits(long n)
{
    long res = 0;
    for (int i = 0; i < 32; ++i)
    {
        res <<= 1;
        res+=(n&1);
        n>>=1;
    }
    return res;
}

int main()
{
    int T = 0;
    cin >> T;
    long N = 0;
    long kr = 0;
    for (int ik = 0; ik < T; ik++)
    {
        cin >> N;
        kr = reverseBits(N);
        cout << kr << endl;
    }
    return 0;
}

