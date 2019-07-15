#include<iostream>
using namespace std;

bool isPalindrome(char *str, int s, int e)
{
    if(s>=e)
    {
        return true;
    }

    if(str[s] == str[e])
    {
        return isPalindrome(str, s+1, e-1);
    }

    return false;
}

int main()
{
    int t, n;
    cin >> t;
    char str[100];

    while(t--)
    {
        cin >> n;
        cin >> str;

        if(isPalindrome(str, 0, n-1))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return (0);
}