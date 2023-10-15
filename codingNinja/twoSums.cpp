#include<iostream>
#include<vector>
using namespace std;

string read(int n, vector<int> book, int target)
{
    int left = 0; int right = 0; int sum = 0;
    while (left < n - 1) {
        right = left + 1;
        while (right < n)
        {
            sum = book[left] + book[right];
            if (sum == target)
                return "Yes";
            right++;
        }
        left++;
    }
    
    return "No";
}

int main()
{
    vector<int> book = {1,2};
    string ans = read(book.size(), book, 2);
    cout << ans << endl;
    return 0;
}