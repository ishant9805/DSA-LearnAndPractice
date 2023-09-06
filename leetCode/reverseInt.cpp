#include<iostream>
using namespace std;

int reverse(int x) {
    int k = x;
    int l = 0;        
    int i = 1;
    while (k != 0)
    {
        if (l > INT_MAX/10 || (l == INT_MAX/10 && k%10 > 7))
        {
            return 0;
        }
        if (l < INT_MIN/10 || (l == INT_MIN/10 && k%10 < -8))
        {
            return 0;
        }
        
        l = l*10 + (k%10);
        i++;
        k = k /10;
    }
    return l;
}

int main()
{
    int N = 1534236469;
    cout << reverse(N);
    
}