#include<iostream>
#include <vector>
using namespace std;

int sumOfAllDivisors(int n){
	vector<int> k;
	while(n > 0)
	{
		for (int i = 1; i <= n; i++)
        {
            if(n % i == 0)
            {
                k.push_back(i);
            }
        }
        n--;        
	}
    int sum = 0;
    for (int i = 0; i < k.size(); i++)
    {
        sum += k[i];
    }
    return sum;    
}

int main()
{
    int n;
    cin >> n;
    cout << sumOfAllDivisors(n);
    return 0;
}