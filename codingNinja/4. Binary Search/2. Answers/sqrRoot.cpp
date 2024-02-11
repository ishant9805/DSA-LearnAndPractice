#include<iostream>
#include<vector>
#include<corecrt.h>

using namespace std;

// Using Binary Search
int floorSqrt(int n) {
    int l = 1, h = n;
    while (l <= h)
    {
        long long m = (l+h)/2;
        long long v = m * m;
        if (v <= (long long)(n)) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    return h;
}

int main()
{
    cout << floorSqrt(100) << endl;
    cout << floorSqrt(6) << endl;
    return 0;
}