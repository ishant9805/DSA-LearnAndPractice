#include<iostream>
using namespace std;

bool checkArmstrong(int n){
	int tmp = n;
    int digCubes = 0;
    int digs = 0;
    while (tmp != 0)
    {
        tmp = tmp / 10;
        digs++;
    }
    tmp = n;
    while (tmp != 0)
    {
        digCubes += pow((tmp % 10), digs);
        tmp = tmp /10;
    }
    return digCubes == n;
}

int main()
{
    int n;
    cin >> n;
    cout << checkArmstrong(n);
    return 0;
}