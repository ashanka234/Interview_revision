#include<iostream>
#include<cstring>
using namespace std;

void print_perm(char *str, int l, int r)
{
    if(l==r)
    {
        cout << str << " ";
        return;
    }

    for(int i=l; i<=r; i++)
    {
        swap(str[i], str[l]);
        print_perm(str, l+1, r);
        swap(str[i], str[l]);
    }
}

int main()
{
    char str[5];
    int t;
    cin >> t;

    while(t--)
    {
        cin >> str;
        print_perm(str, 0, strlen(str)-1);
        cout << endl;
    }

    return (0);
}