#include<iostream>
#include<vector>

using namespace std;

pair<int, int> minMax(vector<int> arr, int n) {
    pair<int, int> mM = {INT_MAX,INT_MIN};
    for (int i = 0; i < n; i++)
    {
        mM.first = min(mM.first, arr[i]);
        mM.second = max(mM.second, arr[i]);
    }
    return mM;
}

int check(vector<int> arr, int nthDay, int flowers) {
    int tmp = 0;
    int bq_cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= nthDay)
        {
            tmp++;
        } else{
            tmp = 0;
        }
        if (tmp == flowers) {
            tmp = 0;
            bq_cnt ++;
        }
    }
    return bq_cnt;
}

int roseGarden(vector<int> arr, int k, int m) {
    int mini = 0;
    int n = arr.size();
    pair<int, int> minMa = minMax(arr, n);
    while (minMa.first <= minMa.second)
    {
        int j = (minMa.first + minMa.second) / 2;
        if (check(arr, j, k) >= m) {
            mini = j;
            minMa.second = j - 1;
        } else {
            minMa.first = j + 1;
        }
    }
    if (mini != 0) return mini;
    return -1;
}

int main()
{
    vector<int> v = {7,7,7,7,13,11,12,7};
    cout << roseGarden(v, 3, 2) << endl;
    v = {1,10,3,10,2};
    cout << roseGarden(v, 2, 3) << endl;
    return 0;
}