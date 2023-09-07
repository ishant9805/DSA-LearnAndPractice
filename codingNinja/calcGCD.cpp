#include<iostream>
#include <vector>
using namespace std;

vector<int> factors(int k)
{
    int l = 2;
    vector<int> fax;
    while (k > 1)
    {
        if (k % l == 0)
        {
            k = k / l;
            fax.push_back(l);
        }
        else
        {
            l++;
        }
        
    }
    return fax;
}

void printVector(vector<int> lala)
{
    cout<<"(";
    for (int ik = 0; ik < lala.size(); ik++)
    {
        cout << lala[ik] << ",";
    }
    cout<<")";
    cout << endl;
}

int calcGCD(int n, int m)
{
    int res = 1;
    vector<int> j = factors(n);
    vector<int> k = factors(m);

    // [2,3,3,3]
    // [2,2,2,11]
    printVector(j);
    printVector(k);
    for (int mn = 0; mn < j.size(); mn++)
    {
        cout<<"j[mn]: "<<j[mn];
        for (int nm = 0; nm < k.size(); nm++)
        {
            if (j[mn] == k[nm])
            {
                res = res * j[mn];
                k.erase(k.begin()+nm);
                j.erase(j.begin()+mn);       
            }
        }
    }
    cout<<endl;
    return res;
}

int calcHCF(int m, int n)
{
    int large = min(m, n);
    int hcf = 1;
    for (int dd = 1; dd <= large; dd++)
    {
        if (m % dd == 0 && n % dd == 0)
        {
            hcf = dd;
        }
        
    }
    return hcf;
}

int main()
{
    int a;
    int b;
    cin >> a;
    cin >> b;
    cout << calcGCD(a,b);
    cout << calcHCF(a,b);
    return 0;
}