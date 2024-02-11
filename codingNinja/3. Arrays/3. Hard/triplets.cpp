#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    int left = 0;
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    while (left < n)
    {
        if (arr[left] == arr[left - 1 ] || left != 0)
        {
            left++;
            continue;
        }
        int mid = left + 1, right = n - 1; 
        while (mid < right)
        {
            int ssum = arr[left] + arr[right] + arr[mid];
            if (ssum > 0) {
                right--;
            } else if (ssum < 0) {
                mid++;
            } else {
                cout << arr[left] << arr[mid] << arr[right] << endl;
                res.push_back({arr[left], arr[mid], arr[right]});
                right--;
                mid++;
                while (mid < right && arr[mid] == arr[mid - 1]) mid++;
                while (mid < right && arr[right] == arr[right - 1]) right--;
                
            }
        }
        left++;
    }
    
    return res;
}

int main()
{
    vector<int> v = {-18, 0, 30, 0, -48, 0, -34, -27, -40, -4, -17, -30, -2};
    //-18 0 30 0 -48 0 -34 -27 -40 -4 -17 -30 -2 

    vector<vector<int>> m = triplet(v.size(), v);
    int rowSize = m.size();
    int colSize = m[0].size();
    cout << "[";
    for (int i = 0; i < rowSize - 1; i++)
    {
    cout << "[";
    for (int j = 0; j < colSize - 1; j++)
    {
        cout << m[i][j] << ", ";
    }
    cout << m[i][colSize - 1] << "]" << endl << " ";
    }
    cout << "[";
    for (int i = 0; i < colSize - 1; i++)
    {
    cout << m[rowSize - 1][i] << ", ";
    }
    cout << m[rowSize - 1][colSize - 1] << "]]" << endl;
    return 0;
}