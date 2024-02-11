#include<iostream>
#include<vector>
using namespace std;

int traffic(int n, int m, vector<int> vehicle) {
    int c1 = 0;
    int c0 = 0;
    int ans = INT_MIN;
    int zero = 0;
	
    while (c1 < n)
    {
        if (vehicle[c1] == 0)
        {
            zero++;
        }
        while (zero > m)
        {
            if (vehicle[c0] == 0)
            {
                zero--;
                c0++;
            }

        }
        ans = max(ans, c1 - c0 + 1);
        c1++;
    }
    
    return ans;
}

int main()
{
    vector<int> v = {0, 1, 0, 0, 1, 0};
    int n = traffic(6, 3, v);
    cout << n << endl;
    return 0;
}