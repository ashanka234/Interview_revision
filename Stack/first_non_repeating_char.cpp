#include<iostream>
#include<stack>
using namespace std;

void print_first_NRC(char *str, int n)
{
    stack<int> s;
    int cnt[26] =  {0};

    for(int i=0; i<n; i++)
    {
        s.push(str[i]);
        cnt[str[i] - 'a']++;        //a=0. b=1, c=2....

        while(!s.empty())
        {
            if(cnt[str[i]-'a'] > 1)     //means it has repeated 
            {
                s.pop();
            }
            else        //matlab count 1 hai so yeh answer h current ka
            {
                cout << (char)s.top() << " ";
                break;      //next ke liye check kro seedha
            }
        }

        if(s.empty())       //matlab koi answer nhi mila jo non repeating ho, then -1
        {
            cout << -1 << " ";
        }
    }

    cout << endl;
}

int main()
{
    int t,n;

    cin >> t;
    while(t--)
    {
        cin >> n;
        char *str = new char[n];

        for(int i=0; i<n; i++)
        {
            cin >> str[i];
        }

        print_first_NRC(str, n);
    }

    return (0);
}