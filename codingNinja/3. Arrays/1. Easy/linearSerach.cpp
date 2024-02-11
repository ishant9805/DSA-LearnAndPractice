#include<iostream>
#include<vector>
using namespace std;

int linearSearch(int n, int num, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {2,5,6,2};
    int n = linearSearch(4, 2, arr);
    cout << n << endl;
    return 0;
}