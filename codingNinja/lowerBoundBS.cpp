#include<iostream>
#include<vector>

using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
	for (int i = 0; i < n; i++)
    {
        if (arr[i] >= x)
        {
            return i;
        }
        
    }
    return n;
}

int main()
{
    vector<int> v = {1,2,2,3,3,5};
    int k = lowerBound(v, v.size(), 0);
    cout << k << endl;
    k = lowerBound(v, v.size(), 2);
    cout << k << endl;
    k = lowerBound(v, v.size(), 6);
    cout << k << endl;
    return 0;
}