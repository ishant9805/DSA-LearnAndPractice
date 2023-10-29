#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int longestSuccessiveElements(vector<int>&a) {
    sort(a.begin(), a.end());
    int cnt = 0; int longest = 0;
    int lstSmaller = -2147483648;
    for (int i = 0; i < a.size(); i++) // {1,1,1,2,2,2,3,3,4,100,100,101,101,102}
    {
        if (a[i] - 1 == lstSmaller)
        {
            cnt++;
            lstSmaller = a[i];
        } else if (lstSmaller == a[i]) {
            continue;
        } else {
            lstSmaller = a[i];
            cnt = 1;
        }
        if (cnt > longest)
        {
            longest = cnt;
        }
    }
    return longest;
}

int main()
{
    vector<int> v = {15, 6, 2, 1, 16, 4, 2, 29, 9, 12, 8, 5, 14, 21, 8, 12, 17, 16, 6, 26, 3};
    // vector<int> v = {1, 2, 2, 1};
    int k = longestSuccessiveElements(v);
    cout << k << endl;
    return 0;
}