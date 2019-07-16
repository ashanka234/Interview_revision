#include<iostream>
using namespace std;

int main()
{
    char *str;
    int t, n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        int cnt = 0;
        str = new char[n];
        cin >> str;
        for(int i=0; i<n; i++)
        {
            if(str[i] == '1')
                cnt++;
        }

        cout << cnt * (cnt-1) / 2 << endl;
    }

    return (0);
}