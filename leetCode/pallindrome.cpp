#include<iostream>

using namespace std;

bool pallindrome(int x)
{
    int tmp = x;
    unsigned int rev = 0; // for large integers
    if ( tmp < 0)
    {
        return false;
    }
    while (tmp != 0)
    {
        rev = (rev * 10) + (tmp % 10);
        tmp = tmp / 10;
    }
    if (rev == x)
    {
        return true;
    }
    return false;
}

int main()
{
    int N;
    cin >> N;
    cout << pallindrome(N);
    return 0;
}