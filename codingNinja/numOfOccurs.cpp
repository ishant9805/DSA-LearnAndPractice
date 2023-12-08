#include<iostream>
#include<vector>

using namespace std;

// Brute force approach
int count(vector<int> &arr, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            cnt++;
        }
        
    }
    return cnt;
}

// int count(vector<int>& arr, int n, int x) {
// 	int low = 0, high = n - 1;
//     while (low < high)
//     {
        
//     }
    
// }

int main()
{
    vector<int> v = {1,1,1,2,2,3,3};
    int k = count(v, v.size(), 3);
    cout << k << endl;
    return 0;
}