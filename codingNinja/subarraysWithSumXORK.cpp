#include<iostream>
#include<vector>

using namespace std;

// Brrute Force Approach
int subarraysWithSumK(vector < int > a, int b) {
    int cnt = 0, sz = a.size();
    for (int i = 0; i < sz; i++)
    {
        for (int j = i; j < sz; j++)
        {
            int xum = 0;
            for (int k = i; k <= j; k++)
            {
                xum = xum ^ a[k];
            }
            if (xum == b)
            {
                cnt += 1;
            }
        }
        
    }
    return cnt;
}

int main()
{
    vector<int> v = {1,2,3,2};
    int k = subarraysWithSumK(v, 2);
    cout << k << endl;
    return 0;
}