#include<iostream>
#include<vector>
using namespace std;

bool isDiv(int i) {
    int a = 10;
    int dig;
    cout << "Num: " << i << " & Digits: [";
    while (i / (a / 10) != 0)
    {
        dig = i % a;
        if (a >= 100)
        {
            dig = dig / (a / 10);
        }
        cout << dig << ",";
        if (dig == 0)
        {
            cout << "]" << endl;
            return false;
        }
        if (i % dig != 0)
        {
            cout << "]" << endl;
            return false;
        }
        a *= 10;
    }
    cout << "]" << endl;
    return true;
}
vector < int > findAllSelfDividingNumbers(int lower, int upper) {
    vector<int> res;
    for (int i = lower; i <= upper; i++)
    {
        if (isDiv(i))
        {
            res.push_back(i);
        }
    }
    return res;
}

int main()
{
    vector<int> v = findAllSelfDividingNumbers(111, 150);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}