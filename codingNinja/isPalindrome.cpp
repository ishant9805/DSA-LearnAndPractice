#include<iostream>
#include<string>
using namespace std;

bool isPal(int start, int end, string& str)
{
    if (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        return isPal(start + 1, end - 1, str);
    }
    return true;
}

bool isPalindrome(string& str) {
    return isPal(0, str.size() - 1, str);
}

int main()
{
    string n = "racecar";
    // cin >> n;
    bool a = isPalindrome(n);
    cout << a;
    return 0;
}