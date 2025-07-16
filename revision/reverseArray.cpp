#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// Basic algo
// void reverseArray(vector<int> &arr , int m) {
//     int n = arr.size();
//     vector<int> rev = {};
//     for (int i = 0; i < n-m-1; i++) {
//         rev.push_back(arr[n-i-1]);
//     }
//     for (int i = 0; i < rev.size(); i++)
//     {
//         arr[m+i+1] = rev[i];
//     }
//     return;
// }

// two pointer
void reverseArray(vector<int> &arr , int m) {
    int n = arr.size();
    for (int i = m+1, j = n-1; i <= j; i++,j--)
    {
        swap(arr[i], arr[j]);
        
    }
    
}

int main()
{
    vector<int> v = { 1, 2, 3, 4, 5, 6 }; // 1 2 3 4 5 6 10 9 8 7 => m + (n-m) / 2
    reverseArray(v, 3);
    cout << "[ ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << "]" << endl;
    v = { 10, 9, 8, 7, 6}; // 1 2 3 4 5 6 10 9 8 7 => m + (n-m) / 2
    reverseArray(v, 2);
    cout << "[ ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}