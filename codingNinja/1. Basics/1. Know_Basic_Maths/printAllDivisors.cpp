#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

int sumOfAllDivisors(int n)
{
    int k = 0;
    while (n > 0)
    {
        for(int i = 1; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                // cout << i << " ";
                k += i;
                if(i != n/i) k += n/i;
            }
        }
        n--;
    }
    
    return k;
}

int main()
{
    int n;
    cin >> n;
    cout << sumOfAllDivisors(n);
    return 0;
}