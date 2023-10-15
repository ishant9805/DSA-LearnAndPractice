#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

// Loop method
// string read(int n, vector<int> book, int target)
// {
//     int left = 0; int right = 0; int sum = 0;
//     while (left < n - 1) {
//         right = left + 1;
//         while (right < n)
//         {
//             sum = book[left] + book[right];
//             if (sum == target)
//                 return "Yes";
//             right++;
//         }
//         left++;
//     }
//     return "No";
// }

// Hashmap method
// This function takes three input (size, arr, target) and returns YES or NO, 
// if target exist as sum of two elements in given arr.
// E.g. string result = read(arr_size:int, arr:vector<int>, target:int)
// string read(int n, vector<int> book, int target)
// {
//     map<int, int> mp; int diff = 0;
//     for (int i = 0; i < n; i++)
//     {
//         diff = target - book[i];
//         if (mp.find(diff) != mp.end())
//         {
//             return "YES";
//         }
//         mp.insert({book[i], i});        
//     }
//     return "NO";
// }

// Two pointer solution
string read(int n, vector<int> book, int target)
{
    sort(book.begin(), book.begin() + n);
    int left = 0; int right = n - 1; int sum = 0;
    while (left < right)
    {
        sum = book[left] + book[right];
        if (sum == target) return "YES";
        if (sum > target) right--;
        if (sum < target) left++;
    }
    return "NO";
}

int main()
{
    vector<int> book = {2,8,7,7,5,3,4};
    string ans = read(book.size(), book, 9);
    cout << ans << endl;
    return 0;
}