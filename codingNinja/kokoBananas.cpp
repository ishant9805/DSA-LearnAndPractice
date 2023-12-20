#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int minimumRateToEatBananas(vector<int> v, int h) {
    for (int i = 3; i <= h; i++) {
        vector<int> vTmp(v.size());
        for (int j = 0; j < v.size(); j++)
        {
            vTmp[j] = ceil(v[j] / (float) i);
        }
        int sum = accumulate(vTmp.begin(), vTmp.end(), 0);
        int hrs = 0;
        while (sum > 0) {
            sum -= i;
            hrs++;
            if (hrs > h) break;
        }
        if(hrs == h) {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> v = {3,6,2,8};
    cout << minimumRateToEatBananas(v, 7) << endl;
    v = {7,15,6,3};
    cout << minimumRateToEatBananas(v, 8) << endl;
    
    return 0;
}