#include<iostream>
#include<vector>

using namespace std;

// Brute Force
int floorSqrt(int n) {
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        if (pow(i,2) < n) {
            l = i;
        }
        else if (pow(i,2) == n) {
            return i;
        }
    }
    return l;
}

int main()
{
    cout << floorSqrt(100) << endl;
    cout << floorSqrt(6) << endl;
    return 0;
}