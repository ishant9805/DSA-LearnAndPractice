#include<iostream>
#include<vector>

using namespace std;

// Brute Force approach
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
    int ceil = -1;
    int flr = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= x)
        {
            ceil = a[i];
            break;
        }        
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= x)
        {
            flr = a[i];
        }        
    }
    return {flr, ceil};
}

int main()
{
    vector<int> v = {3,4,7,8,8,10};
    pair<int, int> k = getFloorAndCeil(v, v.size(), 5);
    cout << "pair<" << k.first << ", " << k.second << ">" << endl;
    k = getFloorAndCeil(v, v.size(), 8);
    cout << "pair<" << k.first << ", " << k.second << ">" << endl;
    return 0;
}