#include<iostream>
#include<vector>

using namespace std;

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
int minDays(vector<int> &arr, int m, int k) {
    int mini = 0;
    int n = arr.size();
    pair<int, int> minMa;
    minMa.first = *min_element(arr.begin(), arr.end());
    minMa.second = *max_element(arr.begin(), arr.end());
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
    cout << minDays(v, 2, 3) << endl;
    v = {1,10,3,10,2};
    cout << minDays(v, 3, 2) << endl;
    return 0;
}