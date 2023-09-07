#include<iostream>
#include <vector>
using namespace std;

int sumOfAllDivisors(int n){
	int k = 0;
	while(n > 0)
	{
		for (int i = 1; i <= n; i++)
        {
            if(n % i == 0)
            {
                k += i;
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