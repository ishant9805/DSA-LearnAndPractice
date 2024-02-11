#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int tmp = 0;
    int z = 0;
    int tmp2 = n;
    while (n > 0)
    {
        tmp = n % 10;
        if ((tmp == 1) || (tmp != 0 && tmp2 % tmp == 0))
        {
            z++;
        }
        n = n / 10;
    }
    cout << z << endl;

	return 0;
}
