#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
{
    int same = 0;
	for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j]) {
                same++;
            }
        }
        
    }
    return {same, m + n - same};  
}


int main()
{
    vector<int> arr = { 2,3 }; // 1 2 3 4 5 6 10 9 8 7 => m + (n-m) / 2
    vector<int> arr2 = { 4,5 }; // 1 2 3 4 5 6 10 9 8 7 => m + (n-m) / 2
    pair<int, int> v = findSimilarity(arr, arr2, arr.size(), arr2.size());
    cout << "[ " << v.first << ", " << v.second << "]\n";
    return 0;
}