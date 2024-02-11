#include<iostream>
#include<vector>
using namespace std;

int isSorted(int n, vector<int> a) {
    for (int i = 0; i < n - 1; i++)
    {
        if (!(a[i] <= a[i + 1]))
        {
            return 0;
        }
        
    }
    return 1;
}

int main()
{
    vector<int> v = {4, 5, 4, 4, 4};
    int k = isSorted(v.size(), v);
    cout << k << endl;
    return 0;
}