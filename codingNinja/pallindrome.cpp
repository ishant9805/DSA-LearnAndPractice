#include<iostream>

using namespace std;

bool pallindrome(int n)
{
    int tmp = n;
    int tmp = n;
    int rev = 0;
    while (tmp != 0)
    {
        rev = (rev * 10) + (tmp % 10);
        tmp = tmp / 10;
    }
    if (rev == n)
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