#include<iostream>
#include<vector>
#include<numeric>
#include<set>
using namespace std;


int singleNumber(vector<int>& arr) {
	int sum = accumulate(arr.begin(), arr.end(), 0);
    int setSum = 0;
    set<int> unik;
    for (int x : arr)
    {
        unik.insert(x);
    }
    for (int s : unik)
    {
        setSum += s;
    }
    setSum = 2 * setSum;

    return setSum - sum;
}

int main()
{
    vector<int> arr = {1};
    int x = singleNumber(arr);
    cout << x << endl;
    return 0;
}