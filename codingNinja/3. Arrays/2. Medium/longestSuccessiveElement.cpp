#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
// Solved using sorting method
// int longestSuccessiveElements(vector<int>&a) {
//     sort(a.begin(), a.end());
//     int cnt = 0; int longest = 0;
//     int lstSmaller = -2147483648;
//     for (int i = 0; i < a.size(); i++) // {1,1,1,2,2,2,3,3,4,100,100,101,101,102}
//     {
//         if (a[i] - 1 == lstSmaller)
//         {
//             cnt++;
//             lstSmaller = a[i];
//         } else if (lstSmaller == a[i]) {
//             continue;
//         } else {
//             lstSmaller = a[i];
//             cnt = 1;
//         }
//         if (cnt > longest)
//         {
//             longest = cnt;
//         }
//     }
//     return longest;
// }

// solving using set method
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
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