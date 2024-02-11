#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& v)
{
    int size = v.size();
    int mini = 0;
    for (int i = 0; i < size - 1; i++)
    {
        mini = i;
        for (int j = i; j < size; j++)
        {
            if (v[j] < v[mini])
            {
                mini = j;
            }
        }
        swap(v[i], v[mini]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int l;
    for (int i = 0; i < n; i++)
    {
        cin >> l;
        v.push_back(l);
    }
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;

    selectionSort(v);

    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;

    return 0;
}