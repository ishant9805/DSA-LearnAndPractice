#include<iostream>
#include<string>
using namespace std;

bool isPal(int start, int end, string& str)
{   
    if (str[start] == ' ')
    {
        return isPal(start + 1, end, str);
    }
    if (str[end] == ' ')
    {
        return isPal(start, end - 1, str);
    }
    
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
    string p = str;
    for (int i = 0; i < p.size(); i++)
    {
        p[i] = tolower(p[i]);    
        if (p[i] < 97 || p[i] > 122)
        {
            p.erase(p.begin() + i);
        }
    }
    return isPal(0, p.size() - 1, p);
}

int main()
{
    string n = "race a car";
    bool a = isPalindrome(n);
    cout << a << endl;

    n = "A man, a plan, a canal: Panama";
    a = isPalindrome(n);
    cout << a << endl;

    n = " ";
    a = isPalindrome(n);
    cout << a << endl;

    return 0;
}