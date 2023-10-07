#include<iostream>
#include<vector>
using namespace std;

int traffic(int n, int m, vector<int> vehicle) {
    int c1 = 0;
    int c0 = 0;
	for (int i = 0; i < n; i++)
    {
        if (vehicle[i] == 1)
        {
            c1++;
        }
        else 
        {
            c0++;
        }
        
    }
    if (m > c0)
    {
        return n;
    }
    
    return c1 + m;
}

int main()
{
    vector<int> v = {1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0};
    int n = traffic(25, 17, v);
    cout << n << endl;
    return 0;
}