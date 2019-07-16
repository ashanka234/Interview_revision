#include<iostream>
using namespace std;

int lcs(char *str1, char *str2, int m, int n)
{
    int max_len = 0;
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
            else if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > max_len)
                    max_len = dp[i][j];
            }
            else
            {
                dp[i][j] = 0;
            }
            
        }
    }
    return max_len;
}

int main()
{
    int n1, n2, t;
    char *str1, *str2;
    cin >> t;

    while(t--)
    {
        cin >> n1 >> n2;
        str1 = new char[n1];
        str2 = new char[n2];

        cin >> str1 >> str2;
        
        cout << lcs(str1, str2, n1, n2) << endl;
    }

    return (0);
}