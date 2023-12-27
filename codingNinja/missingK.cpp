#include<iostream>
#include<vector>

using namespace std;

int findNum(vector<int> v, int l) {
    int low = 0, high = v.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] == l) return mid;
        else if (v[mid] < l) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int missingK(vector < int > vec, int n, int k) {
    int cnt = 0;
    int maxi = vec[vec.size() - 1];
    for (int i = 1; i < maxi; i++)
    {
        if (findNum(vec, i) == -1)
        {
            cnt++;
        }
        if (cnt == k)
        {
            return i;
        }   
    }
    return maxi+(k-cnt);
}

int main()
{
    vector<int> v = {4,7,9,10};
    cout << missingK(v, 4, 4) << endl;
    return 0;
}