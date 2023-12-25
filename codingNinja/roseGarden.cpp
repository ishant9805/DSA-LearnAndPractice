#include<iostream>
#include<vector>

using namespace std;

int roseGarden(vector<int> arr, int k, int m) {
    int mini = 1e9;
    int n = arr.size();
    vector<int> pass;
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < pass.size(); k++)
        {
            if (arr[j] == pass[k])
            {
                continue;
            }
            
        }
        
        /* code */
        int tmp = 0;
        int bq_cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= arr[j])
            {
                tmp++;
            } else{
                tmp = 0;
            }
            if (tmp == k) {
                tmp = 0;
                bq_cnt ++;
            }
        }
        if (bq_cnt >= m) {
            mini = min(mini, arr[j]);
        } else {
            pass.push_back(arr[j]);
        }
    }
    if (mini != 1e9) return mini;
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