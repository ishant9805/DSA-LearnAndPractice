#include<bits/stdc++.h>

using namespace std;

bool helper(int n, int k, vector<int> &a, vector<int> &sum, int curr, int ind) {
    if (curr > k) return false;
    if (ind == n) {
        if (curr == k) {
            return true;
        }
        else return false;
    }

    sum.push_back(a[ind]);
    curr += a[ind];
    if (helper(n, k, a, sum, curr, ind+1) == true) {
        return true;
    }
    curr-=a[ind];
    sum.pop_back();
    if (helper(n,k,a,sum,curr,ind+1) == true) {
        return true;
    }
    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    vector<int> v2;
    return helper(n, k, a, v2, 0, 0);
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {22, 17, 19, 46, 48, 27, 22, 39, 20, 13, 18, 50, 36, 45, 4 ,12 ,23, 34, 24, 15 ,42 ,12, 4 ,19, 48, 45, 13, 8, 38 ,10 ,24, 42, 30, 29, 17, 36, 41, 43, 39, 7 ,41, 43, 15, 49, 47, 6, 41, 30, 21, 1 ,7, 2, 44, 49, 30, 24, 35, 5 ,7 ,41, 17, 27, 32, 9, 45 ,40 ,27, 24, 38, 39, 19, 33, 30, 42, 34, 16, 40, 9, 5, 31, 28, 7 ,24, 37, 22, 46, 25, 23, 21, 30, 28, 24, 48, 13};
    string str = isSubsetPresent(94, 84, v1) ? "True" : "False";
    cout << str << endl;
    return 0;
}