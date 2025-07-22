#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;


// pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
// {
//     int same = 0;
// 	for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (arr1[i] == arr2[j]) {
//                 same++;
//             }
//         }
        
//     }
//     return {same, m + n - same};  
// }


pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
{
    unordered_set<int> uset;
    for (int i = 0; i < n; i++)
    {
        uset.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        uset.insert(arr2[i]);
    }

    return {m + n -uset.size() , uset.size()};
    
}

int main()
{
    vector<int> arr = { 2,3 }; // 1 2 3 4 5 6 10 9 8 7 => m + (n-m) / 2
    vector<int> arr2 = { 4,5 }; // 1 2 3 4 5 6 10 9 8 7 => m + (n-m) / 2
    pair<int, int> v = findSimilarity(arr, arr2, arr.size(), arr2.size());
    cout << "[ " << v.first << ", " << v.second << "]\n";
    return 0;
}