#include<iostream>
#include<vector>
using namespace std;

vector<string> printNTimes(int n) 
{
	vector<string> k;
    if (n == 1)
    {
        k.push_back("Coding Ninjas");
        return k;
    }
    else
    {
        k = printNTimes(n-1);
        k.push_back("Coding Ninjas");
        return k;
    }
    
}

int main()
{
    int n;
    cin >> n;
    vector<string> s;
    s = printNTimes(n);
    cout << "[";
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << ",";
    }
    cout << "]";
    
    return 0;
}